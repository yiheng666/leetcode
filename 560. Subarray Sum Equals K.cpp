class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(),ans = 0,sum_i = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        for (int i=0;i<n;i++){
            sum_i += nums[i];
            int sum_j = sum_i - k;
            if (m[sum_j]) ans += m[sum_j];
            m[sum_i]++;
        }
        return ans;
    }
};