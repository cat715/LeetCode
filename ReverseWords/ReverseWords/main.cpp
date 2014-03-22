//
//  main.cpp
//  ReverseWords
//
//  Created by CAT on 14-3-17.
//  Copyright (c) 2014年 Bian GuanLin. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
        string word;
        stack<string> buf; //关于String的堆，保存的是String
        stringstream ss(s);
        while(ss >> word) //抽取ss的值到word,以空格为划分
        {
            buf.push(word);
            //cout << word << endl;
        }
        
        string res = "";
        bool first = true;
        while(!buf.empty())
        {
            if(!first)//对于第一个单词，前面不加空格。
                res += " ";
            res +=  buf.top();
            buf.pop();
            first = false;  
        }  
        s = res;
        cout << s << endl;
    }
};

class Solution2 {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> cal;
        for(auto& t : tokens)
        {
            if (isdigit(t[0]) || t.size()>1)
                cal.push(atoi(t.c_str()));
            else
            {
                int o1, o2;
                o2 = cal.top();
                cal.pop();
                o1 = cal.top();
                cal.pop();
                
                switch(t[0])
                {
                    case '+':
                        cal.push(o1 + o2);
                        break;
                    case '-':
                        cal.push(o1 - o2);
                        break;
                    case '*':
                        cal.push(o1 * o2);
                        break;
                    case '/':
                        cal.push(o1 / o2);
                        break;
                }
            }
        }
        return cal.top();
    }
};
int main(int argc, const char * argv[])
{

    // insert code here...
//    Solution so;
//    string s;
//    getline(cin, s);
//    so.reverseWords(s);
    vector<string> tokens = {"21","1","+","42","*"};
    Solution2 s;
    s.evalRPN(tokens);
    return 0;
}

