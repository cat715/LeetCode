class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n < 1 || m < 1)
        	return 0;
        if(n == 1 || m == 1)
        	return 1;
        vector<int> f(n, 0);
        f[0] = 1;
        for(int i = 0; i < m; i++)
        	for(int j = 1; j < n; j++)
        		f[j] = f[j] + f[j-1];
        return f[n-1];
    }
};