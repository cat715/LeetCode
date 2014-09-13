#include <iostream>
#include <string>
#include <map>
#include <iterator>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        map<char, int> record;
        map<char, int> expect;//duplicate char in T
        int start = 0, end = 0;
        int a = 0, b = 0;
        int len = INT_MAX;
        string result = "";
        if(S.size() < T.size() || S.size() <= 0) return result;
        for(int i = 0; i < T.size(); i++) {
        	record.insert(pair<char,int>(T[i], 0));
            expect[T[i]]++;
        }

        while(end < S.size()) {
        	char tmp = S[end];
        	if(record.find(tmp) != record.end()) { //match one char in T
        		record[tmp]++;
                //cout << tmp << "" << record[tmp] << endl;
        		//if has found all the chars in T
        		if(ifAll(record,expect) && start <= end) {
                    int flag = 1;
        			while(start <= end && flag) { // has T in this section
                        char t = S[start];
                        if(record.find(t) != record.end()) {
                            if(len > end - start) {
                                a = start;
                                b = end; 
                                len = b - a;
                            }
                            record[t]--;
                            if(record[t] < expect[t]) flag = 0;
                        }
                        start++;
                    }
        		}// end ifAll	
        	}
        	end++;
        }
        if(len != INT_MAX)
            for(int i = a; i <= b; i++)
        	   result+=S[i];
        return result;
    }
    bool ifAll(map<char, int> result, map<char,int> expect) {
    	map<char, int>::iterator it_re;
        it_re = result.begin();
        while(it_re != result.end()) {
            //cout << it_re->first <<"\t" << it_re->second << endl;
            if(it_re->second < expect[it_re->first])
                return false;
            it_re++;
        }	
        return true;
    }
};

int main(int argc, char const *argv[])
{
	string S = "aa";//"ADOBECODEBANC";
	string T = "aa";//ABC";
	Solution s;
	cout << s.minWindow(S, T) << endl;
    cout <<"!!";
	return 0;
}