class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = INT_MIN;
        int m = houses.size(), n = heaters.size();
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int i = 0;
        for (int house : houses){
            while ( i < n && heaters[i] < house){
                i++;
            }
            if (i == 0){
                res = max(res,heaters[i] - house);
            }
            else if (i == n){
                res = max(res,houses[m-1] - heaters[n-1]);
            }
            else{
                res = max(res,min(heaters[i] - house,house - heaters[i-1]));
            }
        }
        return res;
    }
};