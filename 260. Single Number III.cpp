class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto& y : nums)
            x ^= y;
        long long mask = x & (-(long long)x);
        vector<int> res = {0, 0};
        for(auto& y : nums) {
            if(y & mask) res[0] ^= y;
            else res[1] ^= y;
        }
        return res;
    }
};