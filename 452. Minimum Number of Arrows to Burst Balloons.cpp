class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size(),count = 1;
        sort(points.begin(),points.end(),cmp);
        int end = points[0][1];
        for (auto item : points){
            if (item[0] > end){
                count++;
                end = item[1];
            }
        }
        return count;
    }
};