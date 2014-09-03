class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n == 0) return -1;
        int start = 0, end = n, mid = 0;
        while(start != end) {
            mid = (start+end)/2;
            if(A[mid] < target)
                start = mid+1;
            else
                end = mid;
        }
        return start;
    }
};