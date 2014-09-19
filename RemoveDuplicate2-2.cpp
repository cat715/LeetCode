class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 2) return n;
        int index = 2;
        for(int i = 2; i < n; i++)
            if(A[index-2] != A[i])
                A[index++] = A[i];
        return index;
    }
};