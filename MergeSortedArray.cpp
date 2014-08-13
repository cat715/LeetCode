#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
    	if (A == NULL || B == NULL || m < 0 || n < 0) return;
    	int *t = (int*)malloc(sizeof(int) * m);
    	for (int i = 0; i < m; i++)
    		t[i] = A[i];
        int i = 0, j = 0, k = 0;
        while(i < m || j < n) {
        	if(i >= m && j < n) A[k++] = B[j++];
        	else if (i < m && j >= n) A[k++] = t[i++];
        	else {
        		if (t[i] <= B[j]) A[k++] = t[i++];
        		else A[k++] = B[j++];
        	}
        }
        free(t);
        for(int tmp = 0; tmp < m + n; tmp++)
        	cout << A[tmp] << "  ";
    }
};

int main() {
	int A[15] =  {};//{1, 3, 5, 7, 20};
	int B[5] = {2, 4, 6, 25, 30};

	Solution s;
	s.merge(A, 0, B, 5);

	system("pause");
	return 0;
}