#include <iostream>
using namespace std;

class Solution {
public:
	double k_th(int A[], int m, int B[], int n, int k) {
		if(m>n) return k_th(B, n, A, m, k);
		if(m == 0) return B[k-1];
		if(k == 1) return min(A[0], B[0]);
		int ia = min(k / 2, m), ib = k - ia;
		if (A[ia - 1] < B[ib - 1])
			return k_th(A + ia, m - ia, B, n, k - ia);
		else if (A[ia - 1] > B[ib - 1])
			return k_th(A, m, B + ib, n - ib, k - ib);
		else
		return A[ia - 1];
	}

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if(total & 0x1)
        	return k_th(A, m, B, n, total/2+1);
        else 
        	return (k_th(A, m, B, n, total/2+1) + k_th(A, m, B, n, total/2))/2.0;
    }
};

int main() {
	int A[2]={1,2};
	int B[2] = {1, 2};
	Solution s;
	cout << s.findMedianSortedArrays(A, 2, B, 2);
	system("pause");
	return 0;
}