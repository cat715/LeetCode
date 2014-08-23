#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        bool neg = false;
        if (x < 0) {
        	neg = true;
        	x = 0 - x;	  
        }
        int r = 0;
        while(x > 0) {
            int a = x % 10;
            x = x / 10;
            r = r * 10 + a;
        }
        if (neg) return r * (-1);
        return r;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int n;
	while(true) {
		cin >> n;
		cout << s.reverse(n) << endl;
	}
	
	system("pause");
	return 0;
}