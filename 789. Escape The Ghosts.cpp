#include <iostream>
#include <vector>
#include <cmath>   
using namespace std;

class Solution_rough {
public:
    bool escapeGhosts(vector<vector<int> >& ghosts, vector<int>& target) {
        vector<int> start(2); 
        vector<vector<int> > visited(10001, vector<int>(10001, 0) );

        start[0] = 0;
        start[1] = 0;
        bool steps = getPath(ghosts, target, 0, 0, 0, visited);

        return steps;
    }

    bool getPath(vector<vector<int> > ghosts, vector<int> target, int x, int y, int steps, vector<vector<int> >& visited) {
        //cout << x << "\t" << y << endl;

        if (x == target[0] && y == target[1] ) return true;

        //check four different positions
        //upper 
        if (y - 1 >= 0 && visited[x][y - 1] == 0) { //0: not visited, 1: visited
            for(int i = 0; i < ghosts.size(); i++) { //check the distance of all ghosts
                if (!getGhostDistance(x, y - 1, ghosts[i], steps + 1)) { //if won't meet any ghost for this step
                    visited[x][y] = 1;
                    return getPath(ghosts, target, x, y - 1, steps + 1, visited);
                }
            }
        }

        //down
        if (y + 1 < 10001 && visited[x][y + 1] == 0 ) { //0: not visited, 1: visited
            for(int i = 0; i < ghosts.size(); i++) { //check the distance of all ghosts
                if (!getGhostDistance(x, y + 1, ghosts[i], steps + 1)) { //if won't meet any ghost for this step
                    visited[x][y + 1] = 1;
                    return getPath(ghosts, target, x, y + 1, steps + 1, visited);
                }
            }
        }

        //left
        if (x - 1 >= 0 && visited[x - 1][y] == 0 ) { //0: not visited, 1: visited
            for(int i = 0; i < ghosts.size(); i++) { //check the distance of all ghosts
                if (!getGhostDistance(x  - 1, y, ghosts[i], steps + 1)) { //if won't meet any ghost for this step
                    visited[x - 1][y] = 1;
                    return getPath(ghosts, target, x - 1, y, steps + 1, visited);
                }
            }
        }

        //right
        if (x + 1 < 10001 && visited[x + 1][y] == 0 ) { //0: not visited, 1: visited
            for(int i = 0; i < ghosts.size(); i++) { //check the distance of all ghosts
                if (!getGhostDistance(x + 1, y, ghosts[i], steps + 1)) { //if won't meet any ghost for this step
                    visited[x + 1][y] = 1;
                    return getPath(ghosts, target, x + 1, y, steps + 1, visited);
                }
            }
        }

        return false;
    }

    bool getGhostDistance(int x, int y, vector<int> ghost, int steps) {
        int distance = abs(ghost[0] - x) + abs(ghost[1] - y);
        if(distance <= steps) return true;

        return false;
    }
};

class Solution {
public:
    bool escapeGhosts(vector<vector<int> >& ghosts, vector<int>& target) {
        int dis = abs(target[0]) + abs(target[1]);
        for (int i = 0; i < ghosts.size(); i++) {
            if (abs(target[0] - ghosts[i][0]) + abs(target[1] - ghosts[i][1]) <= dis)
                return false;
        }

        return true;
    }
};

int main() {
    int const row = 2, col = 2;

    //
    vector<int> target(2);
    target[0] = 0;
    target[1] = 3;

    int a[row][col] = {{1, 0}, {0, 3}};
    vector<vector<int> > graph(row, vector<int>(col));

    for(int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            graph[i][j] =  a[i][j];
        }
    }

    Solution s;
    cout << s.escapeGhosts(graph, target);

    return 0;
}