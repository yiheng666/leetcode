class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        vector<int> row(n),col(n);
        for (int i=0;i<n;i++){
            int maxRow = INT_MIN,maxCol = INT_MIN;
            for (int j=0;j<n;j++){
                maxRow = max(maxRow,grid[i][j]);
                maxCol = max(maxCol,grid[j][i]);
            }
            row[i] = maxRow;
            col[i] = maxCol;
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                res += min(row[i],col[j]) - grid[i][j];
            }
        }
        return res;
    }
};