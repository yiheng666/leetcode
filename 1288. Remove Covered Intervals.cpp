class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){  
            if (a[0] != b[0]) return a[0] < b[0];
            else return a[1] > b[1];
        }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);

        int ans = 0,left = intervals[0][0],right = intervals[0][1];
        bool flag = true;
        for (auto v : intervals){
            if (flag){
                flag = false;
                continue;
            }
            if (left <=v[0] && right >= v[1])
                ans++;
            else if (right >= v[0] && right <= v[1]){
                right = v[1];
            }
            else if (right < v[0]){
                left = v[0];
                right = v[1];
            }
        }
        return intervals.size() - ans;
    }
    
};