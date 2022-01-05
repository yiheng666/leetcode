class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for (int i=0;i<n;i++){
            if (s[i] == '?'){
                char c = 'a';
                while ( (i>0 && s[i-1]==c) || (i<n-1 && s[i+1] ==c) ){
                    c++;
                } 
                s[i] = c;
            }
        }
        return s;
    }
};