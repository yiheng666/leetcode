class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> need,window;
        vector<int> start;
        for (char c : p)
            need[c]++;
        int left = 0,right = 0,len = p.size(),valid = 0;
        while (right < s.size()){
            char a = s[right];
            right++;
            if (need.count(a)){
                window[a]++;
                if (need[a] == window[a])
                    valid++;
            }
            while (need.size() == valid){
                if (right - left == len){
                    start.push_back(left);
                }
                char b = s[left];
                left++;
                if (need.count(b)){
                    if (need[b] == window[b])
                        valid--;
                    window[b]--;
                }
            }
        }
        return start;
    }
};