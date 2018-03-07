#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector< vector<int> > count(26);
        for (int i = 0; i < S.size(); ++i)
        {
        	count[S[i] - 'a'].push_back(i);
        	//cout << "char:\t" << S[i] << "\t" << i << endl;
        }

        int result = 0;

        for (int i = 0; i < words.size(); i++) { //check each words
        	int find = 0, index = -1, s_index = 0;
			 
            cout << "-----" << i << "-----" << endl;
             
            for (s_index = 0; s_index < words[i].size(); s_index++) {
                char c = words[i][s_index];
                //cout << "char:\t" << c << endl;

                int k = 0;
                cout << "count of size for character:\t" << c << "\t " << count[c - 'a'].size() << endl;
                for (k = 0; k < count[c - 'a'].size(); k++)
                    if (count[c - 'a'][k] > index) {
                        index = count[c - 'a'][k]; //find the index of this char
                        cout << "index of :\t" << c << "\tis:\t"<< index << endl; 
                        k = count[c - 'a'].size() + 1;
                        find = 1;
                    }

                if (k == count[c - 'a'].size()) {//has not found the index
                    find = 0; 
                    break;
                }
            }

            if (s_index == words[i].size() && find == 1) {
                cout << "str:\t" << words[i] << "\tResult:\t" << find << endl;
                result = result + find;
            }   	
        }

        return result;
    }
};

int main() {
    string S = "abcefa";
    vector<string> words;
    words.push_back("ab");
    words.push_back("ace");
    words.push_back("cb");
    words.push_back("cc");

    Solution s;
    cout << s.numMatchingSubseq(S, words);

    return 0;
}
