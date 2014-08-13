#include <iostream>
using namespace std;
class Solution {
public:
    int atoi(const char *str) {
    	if (str == NULL) return 0;
    	bool negative = false;
    	while (*str == ' ') str++;
    	if (*str == '-') {
    		negative = true;
    		str++;
    	} 
    	if (*str == '+') {
    		if (negative == true) return 0;
    		str++;
    	}
    		
    	long long res = 0;
    	while(*str != '\0') {
    		if (*str >= '0' && *str <= '9') {
    			res = res * 10 + *str - '0';
    			str++;
    		}
    		else break;
    	}
    	if (negative) res = 0 - res;
    	if (res > INT_MAX) return INT_MAX;
    	if (res < INT_MIN) return INT_MIN;
        return res;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	char a[40] = "-+1";//"12345";
	cout << s.atoi(a);
	return 0;
}