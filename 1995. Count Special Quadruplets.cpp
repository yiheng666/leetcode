class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int res = 0,n = nums.size();
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                for (int k=j+1;k<n;k++){
                    for (int m=k+1;m<n;m++){
                        if (nums[i] + nums[j] + nums[k] == nums[m]) res++;
                    }
                }
            }
        }
        return res;
    }
};