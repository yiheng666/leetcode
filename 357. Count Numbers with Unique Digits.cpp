class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        vector<int> dp(n+1);
        dp[1] = 10;
        for (int i=2;i<=n;i++){
            int a = 9,b = 9;
            for (int j=i-1;j<n;j++){
                a = a * b;
                b--;
            }
            dp[i] = a;
        }
        int res = 0;
        for (int i=0;i<=n;i++){
            res += dp[i];
        }
        return res;
    }
};