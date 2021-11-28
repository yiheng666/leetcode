class Solution {
public:
    unordered_map<int,int> mp;
    int total,n,cur;
    Solution(int m, int n) {
        this->n = n;
        total = m * n;
        cur = total;
    }
    
    vector<int> flip() {
        int index = rand() % cur;
        if (!mp.count(index)) mp[index] = index;
        if (!mp.count(cur-1)) mp[cur-1] = cur-1;
        swap(mp[index],mp[--cur]);
        return {mp[cur]/n,mp[cur]%n};
    }
    
    void reset() {
        mp.clear();
        cur = total;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */