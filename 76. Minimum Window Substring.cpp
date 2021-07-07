class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need,window;
        int start = 0,left = 0,right = 0,valid = 0,len = INT_MAX;
        for (char c : t)
            need[c]++;
        while (right < s.size()){
            char a = s[right];
            right++;
            if (need.count(a)){
                window[a]++;
                if (window[a] == need[a])
                    valid++;
                
            }
            while (valid == need.size()){
                if (right - left < len){
                    start = left;
                    len = right - left;
                }
                char b = s[left];
                left++;
                if (need.count(b)){
                    if (window[b] == need[b])
                        valid--;
                    window[b]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start,len);
    }
};