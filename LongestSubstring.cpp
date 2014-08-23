#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int alpha[256];
        int start = 0;
        for (int i = 0; i < 256; i++)
        	alpha[i] = -1;
        for (int i = 0; i < s.length(); i++) {
        	if(alpha[s[i]] >= start) {
        		max = max > (i-start) ? max : i - start;
        		//cout << max << "\t" << i << "\t" << start << endl;
        		start = alpha[s[i]] + 1;
        		
        	}
        	alpha[s[i]] = i;
        }

        return max >= (s.length()-start) ? max : s.length() - start;
    }
};

int main() {
	//string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789:/?abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789:/?";
	//string str = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
	string str = "ruowzgiooobpple";
	Solution s;
	cout << s.lengthOfLongestSubstring(str);
	return 0;
}