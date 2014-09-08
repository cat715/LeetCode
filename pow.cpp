#include <iostream>
using namespace std;
class Solution {
public:
    double pow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0) {
        	n = 0 - n;
        	x = 1/x;
        }
        int half = n/2;
        double result = 0;
        result = pow(x, half);
        if(n % 2 != 0) {     	
        	result = result * result * x;
        }
        else {
        	result = result * result;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
	int x = -2, n = -2;
	Solution s;
	cout << s.pow(x, n);
	return 0;
}