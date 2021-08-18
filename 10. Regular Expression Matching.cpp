class Solution {
public:
    unordered_map<string,bool> memo;
    bool isMatch(string s, string p) {
        return dp(s,0,p,0);
    }
    bool dp(string s,int i,string p,int j){
        int m = s.size(),n = p.size();
        if (j == n) return i == m;
        if (i == m){
            if ( (n-j) % 2 == 1) return false;
            for (;j+1<n;j+=2){
                if (p[j+1] != '*') return false;
            }
            return true;
        }
        string str = to_string(i) + ',' + to_string(j);
        if (memo.count(str)) return memo[str];

        bool ans = false;
        //字符匹配成功 
        if (s[i] == p[j] || p[j] == '.'){
            //s接着往下匹配
            if (j+1<n && p[j+1] == '*'){
                ans = dp(s,i+1,p,j) || dp(s,i,p,j+2);
            }
            else{//同时匹配下一个字符匹配
                ans = dp(s,i+1,p,j+1);
            }
        }
        else{
            if (j+1<n && p[j+1] == '*'){
                ans = dp(s,i,p,j+2);
            }
            else return false;
        }
        memo[str] = ans;
        return ans;
    }
};