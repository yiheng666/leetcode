class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> need,window;
        for (char c : s1)
            need[c]++;
        int left = 0,right = 0,start = -1,len = s1.size(),valid = 0;
        while (right < s2.size()){
            char a = s2[right];
            right++;
            if (need.count(a)){
                window[a]++;
                if (window[a] == need[a])
                    valid++;
            }
            while (valid == need.size()){
                if (right - left == len){
                    start = left;
                }
                char b = s2[left];
                left++;
                if (need.count(b)){
                    if (window[b] == need[b])
                        valid--;
                    window[b]--;
                }
            }
        }
        return start == -1 ? false: true;
    }
};