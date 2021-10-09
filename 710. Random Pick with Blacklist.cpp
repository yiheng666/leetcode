class Solution {
public:
    int valid;
    unordered_map<int,int> map;
    Solution(int n, vector<int>& blacklist) {
        valid = n - blacklist.size();
        int last = n - 1;
        for (int i:blacklist) map[i] = 999;
        for (int i:blacklist){
            if (i >= valid) continue;
            while (map.count(last)) last--;
            map[i] = last;
            last--;
        }
    }
    
    int pick() {
        int index = rand() % valid;
        if (map.count(index)) return map[index];
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */