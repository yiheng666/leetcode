class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0,n = ages.size(),left = 0,right = 0;
        sort(ages.begin(),ages.end());
        for (int i=0;i<n;i++){
            if (ages[i] <= 14) continue;
            while (ages[left] <= 0.5 * ages[i] + 7) left++;
            while (right + 1 < n && ages[right+1] <= ages[i]) right++;
            res += right - left;
        }
        return res;
    }
};