class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int count = 0;;
        string res = "";
        for (int i=s.size()-1;i>=0;i--){
            if (s[i] == '-') continue;
            res += toupper(s[i]);
            count++;
            if (count % k == 0) res += '-';
        }
        reverse(res.begin(),res.end());
        return res[0] == '-' ? res.substr(1) : res;
    }
};