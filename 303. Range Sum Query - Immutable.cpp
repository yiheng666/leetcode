class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int>& nums) {
        int n = nums.size(),sum = 0;
        for (int i=0;i<n;i++){
            sum += nums[i];
            dp.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return left == 0 ? dp[right] : dp[right] - dp[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */