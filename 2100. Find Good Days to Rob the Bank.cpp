class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        if(security.size() <= time * 2)return {};
        int n = security.size();
        vector<int> left(n,0),right(n,0),res;
        for (int i=1;i<n;i++){
            if (security[i-1] >= security[i]){
                left[i] = left[i-1] + 1;
            }
        }
        for (int i=n-2;i>=0;i--){
            if (security[i] <= security[i+1]){
                right[i] = right[i+1] + 1;
            }
        }
        for (int i=0;i<n;i++){
            if (left[i] >= time && right[i] >= time) res.push_back(i);
        }
        return res;
    }
};