class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
    	vector<int> result;
        if(L.size() == 0) return result;
        int wordLength = L.front().length();
        if(S.length() < L.size()* wordLength) return result;
        map<string, int> wordCount;
        for(int i = 0; i < L.size(); i++)
        	++wordCount[L[i]];
        map<string, int> cur;
        for(int i = 0; i <= S.size() - wordLength * L.size(); i++) {
        	cur.clear();
        	int j = 0;
        	for(j = 0; j < L.size(); j++) {
        		string word = S.substr(i+j*wordLength, wordLength);
        		if(wordCount.find(word) == wordCount.end())
        			break;
        		cur[word]++;
        		if(cur[word] > wordCount[word])
        			break;
        	}
        	if (j == L.size())
        		result.push_back(i);
        }
        return result;
    }
};