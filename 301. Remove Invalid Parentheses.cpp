class Solution {
public:
    vector<string> res;
    vector<string> removeInvalidParentheses(string s) {
        remove(s, {'(', ')'}, 0, 0);
        return res;
    }
    
    void remove(std::string s, const vector<char>& par, int m, int n) {
        int stack = 0;
        for (int i = m; i < s.length(); i++) {
            if (s[i] == par[0]) stack++;
            if (s[i] == par[1]) stack--;
            if (stack >= 0) continue;
            for (int j = n; j <= i; j++) {
                if (s[j] == par[1] && (j == n || s[j-1] != par[1])) {
                    string ss = s.substr(0, j) + s.substr(j + 1);
                    remove(ss, par, i, j);
                }
            }
            return;
        }
        reverse(s.begin(), s.end());
        if (par[0] == '(') {
            remove(s, {par[1], par[0]}, 0, 0);
        } else {
            res.push_back(s);
        }
    }
};