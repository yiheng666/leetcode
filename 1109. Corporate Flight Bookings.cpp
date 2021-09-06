class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> v(n,0),ans(n,0);
        for (int i=0;i<bookings.size();i++){
            int left = bookings[i][0] - 1,right = bookings[i][1] - 1,value = bookings[i][2];
            v[left] += value;
            if (right + 1 < n)
                v[right+1] -= value;
        }
        ans[0] = v[0];
        for (int i=1;i<n;i++){
            ans[i] = ans[i-1] + v[i];
        }
        return ans;
    }
};