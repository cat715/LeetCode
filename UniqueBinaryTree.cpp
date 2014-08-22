#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int re = 0;
        vector<int> f(n+1, 0);
        f[0] = 1; 
        f[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
        	for (int k = 1; k <= i; k++)
        		f[i] = f[i] + f[k-1] * f[i-k];
        }
        return f[n];
    }
};

int main() {
	int n;
	cin >> n;
	Solution s;
	while(n) {
		cout << s.numTrees(n) << endl;
		cin >> n;
	}
	return 0;
}