class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        string res = "";
        set<string> st;
        for (string s : words){
            int n = s.size();
            if (n == 1 || st.count(s.substr(0,n-1))){
                res = n > res.size() ? s : res;
                st.insert(s);
            }
        }
        return res;
    }
};