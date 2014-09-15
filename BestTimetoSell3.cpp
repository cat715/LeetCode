class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	if(prices.size() == 0) return 0;
        int peak = 0, maxP = 0, valley = 0;
        int n = prices.size();
        std::vector<int> f(n, 0);
        vector<int> g(n, 0);
        for(int i = 1, valley = prices[0]; i < n; i++) {
        	valley = min(valley, prices[i]);
        	f[i] = max(f[i-1], prices[i] - valley);
        }
        for(int i = n - 2, peak = prices[n-1]; i >= 0; i--) {
        	peak = max(peak, prices[i]);
        	g[i] = max(g[i+1], peak-prices[i]);
        }
        for(int i = 0; i < n; i++)
        	maxP = max(maxP, f[i]+g[i]);
        return maxP;
    }
};