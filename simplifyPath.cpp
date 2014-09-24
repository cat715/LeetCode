class Solution {
public:
    string simplifyPath(string path) {
        if(path.size() <= 0) return NULL;
        string result;
        int i = 0;
        stack<string> s;
        while(i < path.size()) {
        	int index = i;
        	string tmp;
        	while(i < path.size() && path[i] != '/') {
        		tmp = tmp + path[i];
        		i++;
        	}
        	if(index != i) {
        		if(tmp == "..") {
        			if(!s.empty())
        				s.pop();
        		}
        		else if (tmp != ".")
        			s.push(tmp);
        	}
        	i++;
        }
        while(!s.empty()) {
        	string tmp = s.top();
        	s.pop();
        	result = "/" + tmp + result;
        }
        if(result.length() == 0)
        	return "/";
        return result;
    }
};