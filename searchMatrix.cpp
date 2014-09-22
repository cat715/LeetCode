class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size() == 0) return false;
        int row = matrix.size();
        int col = matrix[0].size();
        int x = 0, y = col-1;
        while(x >= 0 && x < row && y >=0 && y < col) {
            if(matrix[x][y] == target)
                return true;
            if(y > 0 && matrix[x][y-1] >= target)
                y--;
            else if(x < row - 1 && matrix[x+1][y] <= target)
                x++;
            else {
                x++;
                y--;
            }
        }
        return false;
    }
};