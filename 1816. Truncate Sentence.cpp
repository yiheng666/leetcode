class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.size();
        int index = n;
        for (int i=0;i<s.size();i++){
            if (s[i] == ' ') k--;
            if (k == 0){
                index = i;
                break;
            }
        }
        return s.substr(0,index);
    }
};