#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0, j = 0, n_start = start.size(), n_end = end.size();

        if(n_start != n_end) return false;
        while(i < n_start && j < n_start) {
            while (start[i] == 'X') i++; //skip X
            while (end[j] == 'X') j++; //skip X

            if(i == n_start && j == n_start) return true; //both to the end with X
            
            if(i == n_start || j == n_start || start[i] != end[j]) return false; // either one ends, not equal

            if(start[i] == 'R' && i > j) return false;
            if (start[i] == 'L' && i < j) return false;
            ++i;
            ++j;
        }

        return true;
    }
};

int main() {
    string start = "RXXLRXRXL", end = "XRLXXRRLX";
    Solution s;
    cout << s.canTransform(start, end) << endl;

    return 0;
}