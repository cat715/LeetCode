class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
    	vector<string> res;
        if(s.size()<=0 || dict.size() <= 0) return res;
        help(s, dict, res, 0, "");

    }
    void help(String s, unordered_set<string> &dict, vecotr<string> &res, int start, string item) {
    	if(start >= s.size())
    		res.push_back(item);

    }
};