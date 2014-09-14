class Solution {
public:
    void sortColors(int A[], int n) {
        int a = 0, b = 0, c = 0;
        for(int i = 0; i < n; i++) {
            if(A[i] == 0) a++;
            else if(A[i] == 1) b++;
            else c++;
        }
        for(int i = 0; i < n; i++) {
            if(i >= 0 && i < a)
                A[i] = 0;
            else if(i >= a && i < a+b)
                A[i] = 1;
            else 
                A[i] = 2;
        }
    }
};