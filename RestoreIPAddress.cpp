#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip;
        if(s.length() < 4 || s.length() > 12) return result;
        dfs(s, 0, 0, ip, result);
        return result;
    }
    void dfs(string s, int start, int no, string ip, vector<string> &result) {
    	if(no == 4 && start == s.length()) {
    		ip.resize(ip.size()-1);
    		result.push_back(ip);
    		return;
    	}
    	if(s.size() - start > 3 * (4 - no)) return;
    	if(s.size() - start < (4 - no)) return;
    	int m = 0;
    	for(int i = start; i < start + 3; i++) {
    		m = m * 10 + (s[i] - '0');
    		if(m <= 255) {
    			ip+=s[i];
    			dfs(s, i+1, no+1, ip+'.', result);
    		}
    		if(m == 0) break;
    	}
    }
};

int main(int argc, char const *argv[])
{
	string s = "25525511135";
	Solution ss;
	vector<string> result = ss.restoreIpAddresses(s);
	for(int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	return 0;
}