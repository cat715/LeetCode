#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool isBipartite(vector<vector<int> > & graph) {

        int A[101] = {0}, B[101] = {0};
        int A_Node = 0, B_Node = 0;

        if( graph.size() == 0 || (graph[0].size() ==0 && graph.size() ==1 )) return true;

        for(int i = 0; i < graph.size(); i++) {
            //cout << i << "*****" << endl;

            //if this node doest no include in A or B
            if (A[i] == 0 && B[i] == 0) {
                A[i]++; 
                //cout << i << "in A" << endl;
                A_Node++;
            }

            //check the connections for each node 
            for(int j = 0; j < graph[i].size(); j++) {
                if (A[i] > 0) { //if this node is already in A
                    if (A[graph[i][j]] > 0) // if the connection node is already in A
                        return false;
                    if (B[graph[i][j]] == 0){ //if the connectio node is not in B 
                        B[graph[i][j]]++;
                        //cout << graph[i][j] << " in B" << endl;
                        B_Node++;
                    }
                }

                if(B[i] > 0) {
                    if (B[graph[i][j]] > 0) 
                        return false;
                    if (A[graph[i][j]] == 0){
                        A[graph[i][j]]++;
                        //cout << graph[i][j] << " in A" << endl;
                        A_Node++;
                    }
                }
            }
        }

        if(A_Node > 0 && B_Node > 0)
            return true;

        return false;
    }
};


int main() {

    int a[4][2] =  { {1,3}, {0,2}, {1,3}, {0,2} };

    vector<vector<int> > graph(1, vector<int>(0));//(4, vector<int>(2));

    /*for(int i = 0; i < 4; ++i){
        for (int j = 0; j < 2; ++j){
            graph[i][j] =  a[i][j];
        }
    }*/ 

    Solution s;
    cout << s.isBipartite(graph);

    return 0;
}
