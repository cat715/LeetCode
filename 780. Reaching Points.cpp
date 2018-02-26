#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution_RunTimeError {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) return true;
        if (sx > tx || sy > ty) return false;
        //cout << "x:\t" << sx << "\ty\t" << sy << endl;

        bool result = reachingPoints(sx+sy, sy, tx, ty) || reachingPoints(sx, sx+sy, tx, ty);

        return result;
    }
};


class Solution_ExceedTimeLimit {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) return true;
        if (sx > tx || sy > ty) return false;
        
        queue<int> x, y;
        x.push(sx);
        y.push(sy);

        int x_top = 0, y_top = 0;

        while( !x.empty()) {
            x_top = x.front();
            y_top = y.front();
            x.pop();
            y.pop();
            cout << "x:\t" << x_top << "\ty\t" << y_top << endl;

            if (x_top == tx && y_top == ty) return true;
            if (x_top > tx || y_top > ty) continue;

            //x, y => x+y, y
            x.push(x_top + y_top);
            y.push(y_top);

            //x, y => x, x+y
            x.push(x_top);
            y.push(x_top + y_top);

        }

        return false;
    }
};

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) { 
            if (tx > ty) {
                if(sy == ty) return (tx - sx) % ty == 0;
                tx %= ty;
            }
            else{
                if(sx == tx) return (ty - sy) % tx == 0;
                ty %= tx;
            }
        }
        return false;
    }
};

int main() {
    int a[4] = {9, 2, 9, 11};//{6,5,11,16};//{35, 13, 455955547, 420098884}; //{1, 1, 3, 5}; //{9, 10, 9, 19};//{3, 3, 12, 9};//

    Solution s;
    cout << s.reachingPoints(a[0], a[1], a[2], a[3]);

    return 0;
}