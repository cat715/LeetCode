class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
        if(S.empty()) return result;
        sort(S.begin(), S.end());
        vector<int> path;
        subsets(S, path, 0, result);
        return result;
    }
    
    void subsets(const vector<int> &S, vector<int> &path, int step, vector<vector<int> > &result)  {
        if (step == S.size()) {
            result.push_back(path);
            return;
        }
        // 不选 S[step]
        subsets(S, path, step + 1, result);
        // 选 S[step]
        path.push_back(S[step]);
        subsets(S, path, step + 1, result);
        path.pop_back();
    }
};