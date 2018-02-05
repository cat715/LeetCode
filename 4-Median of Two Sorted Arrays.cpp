#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int index_1 = 0, index_2 = 0, index = 0;
        vector<int> result;

        int len1 = nums1.size(), len2 = nums2.size();
        //cout << len1 << "\t" << len2 << endl;

        while(index_1 < len1 || index_2 < len2) {
            //all left
            if(index_1 < len1 && index_2 < len2) {
                if (nums1[index_1] <= nums2[index_2]) {
                    result.push_back(nums1[index_1]);
                    index_1++;
                }
                else {
                    result.push_back(nums2[index_2]);
                    index_2++;
                }
            }

            //only num1
            if (len2 == 0 || (index_2 >= len2 && index_1 < len1) ) {
                result.push_back(nums1[index_1]);
                index_1++;
            }

            //only num2
            if(len1 == 0 || (index_1 >= len1 && index_2 < len2) ) {
                result.push_back(nums2[index_2]);
                index_2++;
            }
        }

        int length = result.size();
        //cout << endl << length << endl;
        if (length % 2 == 0) {
            return (double)(result[length/2 - 1] + result[length/2])/2;
        }
        else {
            return (double) result[(length-1)/2];
        }
    }
};

int main() {

    Solution s;
    int n1[] = {1, 3}, n2[] = {2};
    vector<int> nums1(n2, n2+1);
    vector<int> nums2;

    double result = s.findMedianSortedArrays(nums1, nums2);
    cout << result << endl; 
    return 0;

}