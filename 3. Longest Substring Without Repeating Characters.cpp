class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> window;
        int left = 0,right = 0,ans = 0;
        while (right < s.size()){
            char a = s[right];
            right++;
            window[a]++;
            while (window[a] > 1){
                char b = s[left];
                left++;
                window[b]--;
            }
            ans = max(ans,right - left);
        }
        return ans;
    }
};