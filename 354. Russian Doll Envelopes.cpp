class Solution {
public:
    static bool cmp(vector<int> v1,vector<int> v2){
        if (v1[0] != v2[0]) return v1[0] < v2[0];
        else return v1[1] > v2[1];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        int n = envelopes.size();
        vector<int> dp(n,1),temp(n);
        for (int i=0;i<n;i++)
            temp[i] = envelopes[i][1];
        for (int i=0;i<n;i++){
            for (int j=0;j<i;j++){
                if (temp[i] > temp[j])
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        int ans = 0;
        for (int i=0;i<n;i++)
            ans = max(ans,dp[i]);
        return ans;
    }
};