#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int y = 0, r = 0;
        int tmp = x;
        if (x < 0) return false;
        while(tmp) {            
            r = tmp % 10;
            tmp = tmp/10;
            y = y * 10 + r;
            cout << "r:" << r <<"\t" << y << endl;
        }
        if (x == y) return true;
        return false;
    }
};

int main() {
    int n = -10;
    Solution s;
    cout << s.isPalindrome(n);
    return 0;
}