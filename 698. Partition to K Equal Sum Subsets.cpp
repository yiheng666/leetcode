class Solution {
public:
    static bool cmp(int a,int b){
        return a > b;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0,n = nums.size();
        vector<int> container(k,0);
        for (int i=0;i<n;i++)
            sum += nums[i];
        if (n < k || sum % k != 0) return false;
        sum /= k;
        //不排序剪枝的话会超时
        sort(nums.begin(),nums.end(),cmp);
        return traverse(nums,0,container,sum);
    }
    bool traverse(vector<int>& nums,int index,vector<int>& container,int traget){
        if (index == nums.size()){
            for (int i=0;i<container.size();i++){
                if (container[i] != traget) return false;
            }
            return true;
        }
        for (int i=0;i<container.size();i++){
            if (nums[index] + container[i] > traget) continue;
            container[i] += nums[index];
            if (traverse(nums,index+1,container,traget)) return true;
            container[i] -= nums[index];
        }
        return false;
    }
};