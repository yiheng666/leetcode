class Solution {
public:
    //从第x台洗衣机的角度出发，当衣服很多时，它只能一件一件给出去；当衣服很少时，可能同时获得很多衣服
    int findMinMoves(vector<int>& machines) {
        int res = INT_MIN,final = 0,n = machines.size(),sum = 0;
        vector<int> dp(n,0);
        for (int i=0;i<n;i++){
            sum += machines[i];
        }
        if (sum % n != 0) return -1;
        final = sum / n;
        for (int i=0;i<n;i++){
            dp[i] = machines[i] - final;
        }
        for (int i=0;i<n-1;i++){
            res = max(max(res,abs(dp[i])),dp[i+1]);
            dp[i+1] += dp[i];//当左边都为0件的时候，当前需要得到或失去衣服的数量。保证得到或失去的衣服都来自右边
        }
        return  max(res,dp[n-1]);
    }
};