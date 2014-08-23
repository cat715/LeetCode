#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
		for (int idx = 0; idx < strs[0].size(); ++idx) { // 纵向扫描 
			for (int i = 1; i < strs.size(); ++i) {
            	if (strs[i][idx] != strs[0][idx]) return strs[0].substr(0,idx);
            }
        }
        return strs[0];
    }
};

int main() {
	vector<string> str;
	str.push_back("apple");
	str.push_back("apper");
	str.push_back("apples");
	str.push_back("appbds");
	Solution s;
	cout << s.longestCommonPrefix(str);
	string a = "Hello";
	cout << a.substr(4,1);
	system("pause");
	return 0;
}