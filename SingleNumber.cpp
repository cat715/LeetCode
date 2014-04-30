#include <iostream>
#include <cstdlib>
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
    	int result = 0;
    	for (int i = 0; i < n; ++i)
    	{
    		result = result^A[i];
    	}
        return result;
    }
};

int main() {
	int A[] = {1,2,4,5,100,2,4,1,99,5,100};
	Solution s;
	int result = s.singleNumber(A,sizeof(A)/sizeof(A[0]));
	cout << sizeof(A)/sizeof(A[0]) << endl;
	cout << result << endl;
	return 0;
}