#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector< vector<string> > partition(string s) {
        std::vector< std::vector<string> > list;
        if (s.length() == 0 || s == " ")
        	return list;
        std::vector<string> tempList;
        dfs(list, tempList, s); //递归调用函数进行分解
        //cout << list.size();
        return list;
    }
    //传递的是地址，否则得不到结果
	void dfs(vector< vector<string> > &list, vector<string> &tempList, string s ){
        if(s.length() == 0){ //已经递归到最后一位，tempList保存此次递归的结果，保存到list中
            list.push_back(tempList);
        }
        int len = s.length(); //待分解子串的长度
        for(int i = 1; i <= len; i++){ //循环依次分解
            string tempStr = s.substr(0,i);
            if(isPalindrome(tempStr)){
                tempList.push_back(tempStr); //如果是回文字符串，保存到templist，继续分解剩下的部分
                //cout << tempStr << endl;
                dfs(list, tempList, s.substr(i)); //从第i位开始到结尾，是否可以分解
                tempList.pop_back(); //????
            }
        }
    }

    bool isPalindrome(string s) {

    	int i = 0;
    	int j = s.length() - 1;
    	// cout << s <<" " << i << " " << j << endl;
    	while (i < j) {
    		// cout << s[i] <<" " << s[j] << endl;
    		if (s[i] != s[j])
    			return false;
    		i++;
    		j--;
    	}
    	return true;
    }
};


int main() {
	string ex = "abba";
	std::vector< std::vector<string> > v;
	Solution s;
	v = s.partition(ex);
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
			cout << v[i][j] << " " ;
		cout << endl;
	}
	//cout << sizeof(ex)/sizeof(char);
	// cout << s.isPalindrome(ex) << endl;
}