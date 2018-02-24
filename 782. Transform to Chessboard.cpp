#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution_Easy {
public:
    int movesToChessboard(vector<vector<int> > & board) {
        int N=board.size(),row_bal=0,col_bal=0,c=0,d=0;
        for(int i=0;i<N;++i){
            row_bal+=board[0][i]?1:-1;
            col_bal+=board[i][0]?1:-1;
            if(i&1){
                c+=board[0][i];
                d+=board[i][0];
            }
        }
        if(row_bal>1||row_bal<-1||col_bal>1||col_bal<-1)     return -1;
        for(int i=1;i<N;++i)
            for(int j=1;j<N;++j)
                if(board[i][j]^board[i][0]^board[0][j]^board[0][0])      return -1;
        
        if(!row_bal)      return min(N/2-c,c) + min(N/2-d,d);
        else        return (row_bal>0?c:N/2-c) + (col_bal>0?d:N/2-d);
    }
};


class Solution {
public:
    int movesToChessboard(vector<vector<int> > & board) {
        int N = board.size(), checkValid = -1, check_row = -1;

        //===== 1 check if the first row meets the requrirement of #1 & #0 for a chess board =====//
        checkValid = checkValidRow(board[0], board[0].size() );
        if (checkValid == -1) return -1;

        // get the swap moves of first column 
        int col_move = getSwapMoves(board[0], checkValid, N);

        if(N%2 ==0) {
            int find_min = getSwapMoves(board[0], 1-checkValid, N);
            if (find_min < col_move) {
                col_move = find_min;
                checkValid = 1-checkValid;
            }
        }

        //==== 2 check all the columns starts with checkValid if its rows meet the requirement =====//  
        vector<int> col;
        for(int i = 0; i < N; i++) { //col
             if (board[0][i] == checkValid) { //starts with checkValid
                col.clear();
                check_row = -1;
                for(int j = 0; j < N; j++) { //row
                    col.push_back(board[j][i]);
                }
                check_row = checkValidRow(col, N);
                //cout << "check col:\t" << i << "\tresult:\t" << check_row << endl;
                if (check_row == -1) return -1;
             }
        }

        if(col.size() == 0) return -1;
        int row_move = getSwapMoves(col, check_row, N);

        if(N%2 ==0) {
            int find_min = getSwapMoves(col, 1-check_row, N);
            if (find_min < row_move) {
                row_move = find_min;
                check_row = 1-check_row;
            }
        }

        //cout << "col_move:\t" << col_move << "\trow_move:\t" << row_move << endl;

        if(col_move == -1 || row_move == -1) return -1;

        return col_move + row_move;
    }

    int checkValidRow(vector<int> row, int N) {
        if (N == 0) return -1;

        int count_1 = 0;

        for(int i = 0; i < N; i++) {
            count_1 = count_1 + row[i];
        }

        if (N % 2 == 0 && count_1 == N/2) return row[0];
        if (N % 2 == 1) {
            if (count_1 == N - count_1 + 1) return 1;
            if (count_1 == N - count_1 - 1) return 0;
        }
        return -1;
    }

    int getSwapMoves(vector<int> vec, int first, int col_N) {
        vector<int> standard_row;
        int col_moves = 0;

        //cout << "first element is:\t" << first << endl;
        standard_row.push_back(first);

        for(int i = 1; i < col_N; i++) {
            standard_row.push_back(1 - standard_row[i-1]);
            col_moves = col_moves + (vec[i] ^ standard_row[i]); //same: 0, not same: 1
            //cout << vec[i] << "\t" << standard_row[i] <<"\t" << (vec[i] ^ standard_row[i]) << endl;
            //cout << "col_moves:\t" << col_moves << endl;
        }

        col_moves = col_moves + (vec[0] ^ standard_row[0]);
        //cout << "===== moves:\t" << col_moves << endl;

        //col_moves: different columns compared board[0] with the correct row
        if (col_moves % 2 == 1) return -1;
        if (col_moves >= 0) return col_moves / 2;

        //cout << "col_moves:\t" << col_moves << endl; 
        return -1;
    }
};


int main() {
    const int row = 6, col = row;
    int a[row][col] = {{0,0,1,0,1,1},{1,1,0,1,0,0},{1,1,0,1,0,0},{0,0,1,0,1,1},{1,1,0,1,0,0},{0,0,1,0,1,1}};
    //{{0,1,1,0},{0,1,1,0},{1,0,0,1},{1,0,0,1}}; = 2
    //{{1,0},{1,0}}; = -1
    //{{1,1,0},{0,0,1},{0,0,1}}; = 2 
    //{{0,0,1,1,1,1,0},{0,0,1,1,1,1,0},{0,0,1,1,1,1,0},{0,1,0,0,1,1,1},{0,1,0,0,1,1,1},{0,1,0,0,1,1,1},{0,0,1,1,1,1,0}}; = -1
    // { {0,1,1,0}, {0,1,1,0}, {1,0,0,1}, {1,0,0,1} }; =

    vector<vector<int> > graph(row, vector<int>(col));

    for(int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            graph[i][j] =  a[i][j];
        }
    } 

    Solution s;

    cout << s.movesToChessboard(graph) << endl;;

    return 0;
}


/*
int getFirstNode(vector<int> vec, int count) {
        int first = 0;

        for(int i = 0; i < count; i++) {
            first = first + vec[i];
        }

        if(first == 0) return first;

        //cout << "count:\t" << count  <<"\tfirst:\t" << first << endl;
        if(count % 2 == 0) //even columns
            if (count / 2 == first) first = vec[0];
            else return -1;

        if(count % 2 == 1) //odd columns
            if (first == count - first + 1) first = 1;
            else if (first == count - first - 1) first = 0;
            else return -1;

        //cout << "first:\t" << first << endl;
        return first;
    }

*/
