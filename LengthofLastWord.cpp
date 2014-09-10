#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int i = 0, start = 0, len = 0;
        int n = strlen(s);
        while(i < n) {
            while(s[i] != ' ' && i < n)
                i++;
            //cout<<start<<"\t"<<i<<endl;
            len = i - start;
            while(s[i] == ' ')
                i++;
            start = i;
        }
        return len;
    }
};

int main(int argc, char const *argv[])
{
	char s[] = {"a   b   "};//{"Hello World"};
	Solution so;
	cout << so.lengthOfLastWord(s);
	return 0;
}