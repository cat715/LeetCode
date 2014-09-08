#include <iostream>
using namespace std;
class Solution {
public:
    bool canJump (int A[], int n) {
		if (n == 0) return true;
		// 逆向下楼梯,最左能下降到第几层 int left_most = n - 1;
          for (int i = n - 2; i >= 0; --i)
              if (i + A[i] >= left_most)
                  left_most = i;
          return left_most == 0;
    }
};
int main(int argc, char const *argv[])
{
	int A[] = {2, 0 , 0};
	Solution s;
	cout << s.canJump(A, 3);
	return 0;
}