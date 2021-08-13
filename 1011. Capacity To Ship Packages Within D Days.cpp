class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left=0,right=1;
        for (int i=0;i<weights.size();i++){
            left = max(left,weights[i]);
            right += weights[i];
        }
        while (left < right){
            int mid = left + (right - left) / 2;
            if (f(weights,mid) <= days){
                right = mid;
            }
            else left = mid + 1;
        }
        return left;
    }
    int f(vector<int>& weights,int k){
        int days = 0;
        for (int i=0;i<weights.size();){
            int cap = k;
            while (i < weights.size()){
                if (weights[i] <= cap){
                    cap -= weights[i];
                    i++;
                } 
                else break;
            }
            days++;
        }
        return days;
    }
};