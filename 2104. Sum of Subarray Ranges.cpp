class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        for (int i=0;i<n;i++){
            int maxN = nums[i];
            int minN = nums[i];
            for (int j=i+1;j<n;j++){
                maxN = max(maxN,nums[j]);
                minN = min(minN,nums[j]);
                res += (maxN - minN);
            }
        }
        return res;
    }
};