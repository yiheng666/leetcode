class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        dp = matrix;
        for (int i=0;i<m;i++){
            for (int j=1;j<n;j++){
                dp[i][j] = dp[i][j] + dp[i][j-1];
            }
        }
        for (int i=1;i<m;i++){
            for (int j=0;j<n;j++){
                dp[i][j] = dp[i][j] + dp[i-1][j];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s1,s2,s3;
        s1 = row1 - 1 < 0 ? 0 : dp[row1-1][col2];
        s2 = col1 - 1 < 0 ? 0 : dp[row2][col1-1];
        s3 = row1 - 1 < 0 || col1 - 1 < 0 ? 0 : dp[row1-1][col1-1];
        return dp[row2][col2] - s1 - s2 + s3;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */