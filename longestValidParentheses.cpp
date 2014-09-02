class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() <= 1) return 0;
        int res = 0, match = 0;
        vector<int> f(s.size(),0);
        for(int i = s.size()-2; i >= 0; i--) {
        	match = i + f[i+1] + 1;
        	if(s[i] == '(' && match < s.size() && s[match] == ')') {
        		f[i] = f[i+1] + 2;
        		if( match + 1 < s.size())
        			f[i] += f[match + 1];
        	}
        	res = max(res, f[i]);
        }
        return res;
    }
};