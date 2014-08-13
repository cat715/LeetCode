#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	if (prices.size() == 0)
    		return 0;
        int maxPrice = prices[prices.size()-1];
        int ans = 0;
        for(int i = prices.size() - 1; i >= 0; i--)
        {
            maxPrice = max(maxPrice, prices[i]);
            ans = max(ans, maxPrice - prices[i]);
        }
        
        return ans;
    }
};

int main(int argc, char const *argv[])
{
	int a[] = {1,2,5,1,4,3};
	vector<int> prices(a, a+6);
	Solution s;
	cout << s.maxProfit(prices) << endl;
	return 0;
}