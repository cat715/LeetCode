#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
    	int N = ratings.size();
    	int *num = new int[N];
    	if(N == 1) return 1;
    	for (int i = 0; i < N; i++) {
    		num[i] = 1;
    		//cout << ratings[i] << " ";
    	}
//    	cout << endl;
    	for (int i = 1; i < N; i++) {
    		if(ratings[i] > ratings[i - 1])
    			num[i] = num[i - 1] + 1;
    		//cout << num[i] << " ";
    	}
//    	cout << endl;
    	for (int i = N - 1; i >= 1; i--) {
    		if(ratings[i - 1] > ratings[i] && num[i-1] <= num[i])
    			num[i - 1] = num[i] + 1;
    	}
    	int result = 0;
    	for (int i = 0; i < N; i++)
    		result += num[i];
    	//cout << result << endl;
        return result;
    }
};

int main() {
	vector<int> rate;
//	for (int i = 0; i < 5; ++i)
//	{
//		int value = rand() % 5;
//		rate.push_back(value);
//	}
	rate.push_back(5);
	rate.push_back(3);
	rate.push_back(1);
	Solution s;
	int num = s.candy(rate);
	system("pause");
	return 0;
}
