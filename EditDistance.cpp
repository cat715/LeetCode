class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        int f[len1+1][len2+1];
        for(int i = 0; i <= len1; i++)
        	f[i][0] = i;
        for(int i = 0; i <= len2; i++) 
        	f[0][i] = i;
        for(int i = 1; i <= len1; i++) {
        	for(int j = 1; j <= len2; j++) {
        		if(word1[i-1] == word2[j-1])
        			f[i][j] = f[i-1][j-1];
        		else {
        			int mn = min(f[i-1][j-1], f[i-1][j]);
        			f[i][j] = 1 + min(f[i][j-1], mn);
        		}
        	}
        }
        return f[len1][len2];
    }
};