class Solution {
private:
    class myQueue{
    public:
        deque<int> dq;
        void pop(int value){
            if (!dq.empty() && dq.front() == value){
                dq.pop_front();
            }
        }
        void push(int value){
            while (!dq.empty() && value > dq.back()){
                dq.pop_back();
            }
            dq.push_back(value);
        }
        int getFront(){
            return dq.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        myQueue dq;
        vector<int> res;
        int n = nums.size();
        for (int i=0;i<k;i++){
            dq.push(nums[i]);
        }
        res.push_back(dq.getFront());
        for (int i=k;i<n;i++){
            dq.pop(nums[i-k]);
            dq.push(nums[i]);
            res.push_back(dq.getFront());
        }
        return res;
    }
};