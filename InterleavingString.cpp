#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool result = false;
        if (s3.length() == s1.length() + s2.length()) {
        	cout << "!!";
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
	string s1 = "aabcc", s2 = "dbbca";
	string s3 = "aadbbcbcac";
	Solution s;
	cout << s.isInterleave(s1, s2, s3) << endl;
	s3 = "aadbbbaccc";
	cout << s.isInterleave(s1, s2, s3) << endl;
	system("pause");
	return 0;
}