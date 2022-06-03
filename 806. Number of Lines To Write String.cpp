class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int line = 0,i = 0,pixels = 0;
        while (i<s.size()){
            pixels = 0;
            while (i<s.size() && widths[s[i]-'a'] + pixels <= 100 ){
                pixels += widths[s[i]-'a'];
                i++;
            }
            line++;
        }
        return {line,pixels};
    }
};