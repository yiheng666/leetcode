class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int dp_i_0 = 0,dp_i_1 = INT_MIN,temp = 0,pre_temp = 0;
        for (int i=0;i<len;i++){
            temp = dp_i_0;
            dp_i_0 = max(dp_i_0,dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1,pre_temp - prices[i]);
            pre_temp = temp;
        } 
        return dp_i_0;
    }
};