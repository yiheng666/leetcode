class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
		//行:matrix.size()
		//列:matrix[0].size()
        int ans = INT_MAX,n = matrix.size();
        vector<vector<int>> dp = matrix;
        for (int i=1;i<n;i++){
            for (int j=0;j<n;j++){
                if (j == 0) dp[i][j] += min(dp[i-1][j],dp[i-1][j+1]);
                else if (j == n-1) dp[i][j] += min(dp[i-1][j-1],dp[i-1][j]);
                else dp[i][j] += min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]));
            }
        }
        for (int j=0;j<n;j++){
            ans = min(ans,dp[n-1][j]);
        }
        return ans;
    }
};