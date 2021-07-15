class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return nSum(nums,4,0,target);
    }
    vector<vector<int>> nSum(vector<int> &nums,int n,int start,int target){
        int len = nums.size();
        vector<vector<int>> ans;
        if (n < 2 || len < n) return ans;
        if (n == 2){
            int low = start,high = len - 1;
            while (low < high){
                int left = nums[low],right = nums[high];
                int sum = left + right;
                if (sum < target){
                    while(low < high && left == nums[low]) low++;
                }
                else if (sum > target){
                    while(low < high && right == nums[high]) high--;
                }
                else{
                    ans.push_back({left,right});
                    while(low < high && left == nums[low]) low++;
                    while(low < high && right == nums[high]) high--;
                }
            }
        }
        else{
            for (int i=start;i<len;i++){
                vector<vector<int>> sub = nSum(nums,n-1,i+1,target-nums[i]);
                for(vector<int> &temp:sub){
                    temp.push_back(nums[i]);
                    ans.push_back(temp);
                }
                while (i < len - 1 && nums[i] == nums[i+1]) i++;
            }
        }
        return ans;
    }
};