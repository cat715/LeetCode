#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int len = 0;
        map<int, bool> used;
        for(int i = 0; i < num.size(); i++)
        	used.insert(pair<int, bool>(num[i],false));

        for(int i = 0; i < num.size(); i++) {
        	if (used[num[i]]) continue;
        	int longest = 1;
        	int n = num[i];
        	used[n] = true;
        	for(int j = n+1; used.find(j) != used.end(); ++j) {
        		used[j] = true;
        		longest++;
        	}
        	for(int j = n-1; used.find(j) != used.end(); --j) {
        		used[j] = true;
        		longest++;
        	}
        	if(len < longest) len = longest;
        }
        return len;
    }
};

int main() {
	vector<int> num;
	num.push_back(100);
	num.push_back(1);
	num.push_back(3);
	num.push_back(150);
	num.push_back(2);

	Solution s;
	cout << s.longestConsecutive(num);
	return 0;
}