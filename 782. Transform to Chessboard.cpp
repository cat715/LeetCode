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
        int start_0 = getSwapMovesWithFirst(board, 0), start_1 = getSwapMovesWithFirst(board, 1);
        int min = start_0 <= start_1 ? start_0 : start_1;
        return min == INT_MAX ? -1 : min;
    }

    int getSwapMovesWithFirst(vector<vector<int> > board, int first) {
        int col_moves = -1, row_moves = -1;
        int N = board.size();

        //===== Check columns row by row =====//
        vector<int> first_row = board[0];
        col_moves = getSwapMoves(first_row, first, N);

        //===== Check rows column by column =====//
        vector<int> first_col;
        for(int i = 0; i < N; i++)
            first_col.push_back(board[i][0]);
                
        row_moves = getSwapMoves(first_col, first, N);
        //if (row_moves == -1) row_moves = getSwapMoves(first_col, 1-first, N);

        //===== return result =====//
        cout << "first:\t" << first << "\tcol_moves:\t" << col_moves << "\trow_moves:\t" << row_moves << endl;
        if(col_moves == -1 || row_moves == -1) return INT_MAX;
        
        return col_moves + row_moves;
    }

    int getSwapMoves(vector<int> vec, int first, int col_N) {
        vector<int> standard_row;
        int col_moves = 0;

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
        if (col_moves > 0) col_moves = col_moves / 2;

        //cout << "col_moves:\t" << col_moves << endl; 
        return col_moves;
    }
};


int main() {
    const int row = 7, col = row;
    int a[row][col] = {{0,0,1,1,1,1,0},{0,0,1,1,1,1,0},{0,0,1,1,1,1,0},{0,1,0,0,1,1,1},{0,1,0,0,1,1,1},{0,1,0,0,1,1,1},{0,0,1,1,1,1,0}} ;
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
