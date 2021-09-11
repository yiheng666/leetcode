class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0,right = height.size() - 1,ans = 0;
        int left_max = height[left],right_max = height[right];
        while (left <= right){
            left_max = max(left_max,height[left]);
            right_max = max(right_max,height[right]);
            if (left_max < right_max){
                ans += left_max - height[left];
                left++;
            }
            else{
                ans += right_max - height[right];
                right--;
            }
        }
        return ans;
    }
};