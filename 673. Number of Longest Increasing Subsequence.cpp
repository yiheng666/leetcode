class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int res = 0,Max = 1;
        vector<int> dp(n,1),combination(n,1);
        for (int i=1;i<n;i++){
            for (int j=0;j<i;j++){
                if (nums[i] > nums[j]){
                    if (dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        combination[i] = combination[j];
                    }
                    else if (dp[j] + 1 == dp[i]){
                        combination[i] += combination[j];
                    }
                }
            }
            Max = max(Max,dp[i]);
        }
        for (int i=0;i<n;i++){
            if (dp[i] == Max) res += combination[i];
        }
        return res;
    }
};