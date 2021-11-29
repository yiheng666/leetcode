class Solution {
public:
/*
根据题解可知： 环形子数组的最大和具有两种可能，一种是不使用环的情况，另一种是使用环的情况

1、不使用环的情况时，直接通过53题的思路，逐步求出整个数组中的最大子序和即可

2、使用到了环，则必定包含 A[n-1]和 A[0]两个元素且说明从A[1]到A[n-2]这个子数组中必定包含负数。【否则只通过一趟最大子序和就可以的出结果】

因此只需要把A[1]-A[n-2]间这些负数的最小和求出来

用整个数组的和 sum减掉这个负数最小和即可实现原环型数组的最大和
*/
    int maxSubarraySumCircular(vector<int>& nums) {
        int Max = nums[0];
        int Cur = nums[0];
        int n = nums.size();
        for (int i=1;i<n;i++){
            if (Cur > 0) Cur += nums[i];
            else Cur = nums[i];
            Max = max(Max,Cur);
        }
        if (n > 2){
            int Sum = nums[0] + nums[n-1];
            int Min = nums[0];
            Cur = 0;
            for (int i=1;i<n-1;i++){
                Sum += nums[i];
                if (Cur < 0) Cur += nums[i]; 
                else Cur = nums[i];
                Min = min(Min,Cur);
            }
            return max(Max,Sum-Min);
        }
        else return Max;
    }
};