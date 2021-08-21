class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> score(n+2,1);
        vector<vector<int>> dp(n+2,vector<int> (n+2,0));
        for (int i=1;i<=n;i++){
            score[i] = nums[i-1];
        }
        for (int i=n;i>=0;i--){
            for (int j=i+1;j<n+2;j++){
                for (int k=i+1;k<j;k++){
                    dp[i][j] = max(dp[i][j],dp[i][k] + dp[k][j] + score[i] * score[k] * score[j]);
                }
            }
        }
        return dp[0][n+1];
    }
};