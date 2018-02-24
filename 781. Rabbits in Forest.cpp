#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int sum = 0, count_oneColor = 0;
        map<int, int> table;//key: #rabits in one color, value: how many times this number has appered in the answer

        for(int i = 0; i < answers.size(); i++) {
            count_oneColor = answers[i] + 1;
            if (table.find(count_oneColor) != table.end()) { //already exist
                if (count_oneColor > table[count_oneColor]) table[count_oneColor]++;
                else {
                    table[count_oneColor] = 1;
                    sum = sum + count_oneColor;
                }
            }
            else {
                table.insert(pair<int, int>(count_oneColor, 1));
            }
        }

        for (map<int,int>::iterator it = table.begin(); it!=table.end(); ++it) {
            sum = sum + it->first;
        }

        return sum;
    }
};

int main() {
    const int n = 5;
    int a[n] = {0,0,1,1,1};
    vector<int> ans(a, a + n); 

    Solution s;
    cout << s.numRabbits(ans);

    return 0;
}