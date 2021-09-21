class Solution {
public:
    int findIntegers(int n) {
        string str = convert(n);
        int res = 0;
        vector<int> dp(33);
        dp[0] = 1;
        dp[1] = 2;
        for (int i=2;i<33;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        for (int i=0;i<str.size();i++){
            if (str[i] == '0') continue;
            res += dp[str.size()-i-1];
            if (i!=0 && str[i-1] == '1')
                return res;
        }
        return res+1;
    }
    string convert(int n){
        string ans;
        while (n > 0){
            ans += (n%2) + '0';
            n /= 2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};