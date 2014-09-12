class Solution {
public:
    string addBinary(string a, string b) {
        if(b == "") return a;
        if(a == "") return b;
        string c="";
        int m = 0, n = 0, k = 0, iA = a.size() -1, iB = b.size() - 1;
        while(iA >= 0 || iB>= 0) {
            m = iA>= 0?a[iA] - '0':0;
            n = iB>= 0?b[iB] - '0':0;
            m = m + n + k;
            k = m / 2;//jinwei
            m = m % 2;
            if(m == 0) c = "0"+c;
            else c = "1"+c;
            iA--;
            iB--;
        }
        if(k == 1) c = "1"+c;
        return c;
    }
};