#include <iostream>
#include <cstdlib>
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
    	int result = 0;
        int j = 1;
        if (n < 0) return -1;
        if (n == 1) return A[0];
    	sort(A, A+n);
        for (int i = 0; i < n - 1; ++i)
        {
            //cout << A[i] << " " << endl;
            if (A[i] == A[i+1]) j++;
            else {
                if (j < 3) return A[i];
                j = 1;
            }
        }
        return A[n-1];
    }
};

int main() {
	//int A[] = {1,2,4,5,100,2,4,1,99,5,100,5,4,2,1,100};
    int A[] = {2,2,3,2};
	Solution s;
	int result = s.singleNumber(A,sizeof(A)/sizeof(A[0]));
	cout << sizeof(A)/sizeof(A[0]) << endl;
	cout << result << endl;
	return 0;
}