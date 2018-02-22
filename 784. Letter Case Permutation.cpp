#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:

    void goForward(string S, int index, vector<string> & result) {
        if (index == S.size()) {
            result.push_back(S);
            return;
        }
        if(isalpha(S[index]) ){ // if it is a letter
            S[index] ^= (1 << 5); // change the letter to upper/lower, +32 to upper, -32 to lower
            goForward(S, index + 1, result); //continue change based on this change
            S[index] ^= (1 << 5); //revert the change to do coninue steps
        } 
        goForward(S, index+1, result);
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        goForward(S, 0, result);
        return result;
    }
};


int main() {
    string str = "a1b2";

    Solution s;
    vector<string> result = s.letterCasePermutation(str);

    for(int i = 0; i < result.size(); i++)
        cout << result[i] << "\t";

    cout << endl;
    return 0;
}