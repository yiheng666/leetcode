class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        for (int i=0;i<s.size();i++){
            string s1 = palindorme(s,i,i);
            string s2 = palindorme(s,i,i+1);
            ans = ans.size() > s1.size() ? ans : s1 ;
            ans = ans.size() > s2.size() ? ans : s2 ;
        }
        return ans;
    }
    string palindorme(string s,int left,int right){
        int n = s.size();
        while (left >=0 && right < n && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
};