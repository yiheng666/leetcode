class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0,left = 0;
        for (int i=0;i<s.size();i++){
            if (s[i] == 'L') left++;
            else left--;
            if (left == 0) ans++;
        }
        return ans;
    }
};