class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = duration;
        for (int i=1;i<timeSeries.size();i++){
            res += min(timeSeries[i]-timeSeries[i-1],duration);
        }
        return res;
    }
};