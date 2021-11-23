class Solution {
public:
    int findLHS(vector<int>& nums) {
		//用map思路简单
        map<int,int> m;
        int res = 0;
        for (int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        auto front = m.begin();
        auto it = m.begin();it++;
        for (;it!=m.end();it++){
            if (it->first - front->first == 1){
                res = max(res,it->second + front->second);
            }
            front++;
        }
        return res;
    }
};
//滑动窗口解法
class Solution {
    public int findLHS(int[] nums) {
        Arrays.sort(nums);
        int begin = 0,res = 0;
        for(int end = 0;end < nums.length;end++){
            while(nums[end] - nums[begin] > 1)
                 begin++;
            if(nums[end] - nums[begin] == 1)
              res = Math.max(res,end - begin + 1);
        }
        return res;
    }
}