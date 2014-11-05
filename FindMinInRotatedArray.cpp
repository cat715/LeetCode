#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int> &num) {
    	if(num.size() <= 0) return -1;
    	int min = num[0];
    	for(int i = 0; i < num.size(); i++) {
    		if(num[i] < min)
    			min = num[i];
    	}
        return min;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> A;
	A.push_back(4);
	A.push_back(5);
	A.push_back(6);
	A.push_back(7);
	A.push_back(1);
	A.push_back(2);
	Solution s;
	cout << s.findMin(A);
	return 0;
}