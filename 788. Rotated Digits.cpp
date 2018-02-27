#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {  
        int result = 0, tmp = 0;
        for(int i = 1; i <= N; i++) {
            /*tmp = isValid(i);
            result = result + tmp;
            if (tmp == 1) cout << i << endl;*/
            result = result + checkRotate(i);
        }

        return result;
    }

    int checkRotate(int n) {
        int result = 0, number = n, mul = 1;
         map<int, int> rotate_map;// = {{2, 5}, {5, 2}, {6, 9}, {9, 6}};
         rotate_map[2] = 5;
         rotate_map[5] = 2;
         rotate_map[6] = 9;
         rotate_map[9] = 6;
         rotate_map[1] = 1;
         rotate_map[0] = 0;
         rotate_map[8] = 8;

        while(number > 0){
            int temp = number % 10;
            if (rotate_map.find(temp) == rotate_map.end()) return 0;
            result = result + rotate_map[temp] *mul;
            number = number / 10;
            mul = mul * 10;
        }

        if (result != n) cout << "N:\t" << n << "\tRotate:\t" << result << endl;
        if (result == n) return 0;

        return 1;
    }

    int isValid(int N) {
        /*
         Valid if N contains ATLEAST ONE 2, 5, 6, 9
         AND NO 3, 4 or 7s
         */
        int validFound = 0;
        while (N > 0) {
            if (N % 10 == 2) validFound = 1;
            if (N % 10 == 5) validFound = 1;
            if (N % 10 == 6) validFound = 1;
            if (N % 10 == 9) validFound = 1;
            if (N % 10 == 3) return 0;
            if (N % 10 == 4) return 0;
            if (N % 10 == 7) return 0;
            N = N / 10;
        }
        return validFound;
    }
};

int main() {
    int N = 100;
    Solution s;
    cout << s.rotatedDigits(N) << endl;

    return 0;
}