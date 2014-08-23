#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {        
        if (A == NULL || n < 1) 
        	return 1;
        int pos = 0;
        while (pos < n) {
        	if (A[pos]!=pos+1 && A[pos]>0 && A[pos]-1<n && A[pos]!=A[A[pos]-1]) {
        		swap(A[pos], A[A[pos]-1]);
        	}
        	else 
        		++pos;
        }
        for (int i = 0; i < n; i++)
        	if (A[i] != i+1)
        		return i+1;
        return n+1;
    }
    void swap(int &a,int &b)   
    {     
        int tmp = a;  
        a = b;  
        b= tmp;  
    }
};

int main() {
	int n[]={2,1};
	Solution s;
	cout << s.firstMissingPositive(n, 2);
	return 0;
}