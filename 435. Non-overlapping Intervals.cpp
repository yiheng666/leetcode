class Solution {
public:
	//不用引用的话这题就超时了，很离谱
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(),count = 1;
        sort(intervals.begin(),intervals.end(),cmp);
        int end = intervals[0][1];
        for (auto item : intervals){
            if (item[0] >= end){
                end = item[1];
                count++;
            }
        }
        return n - count;
    }
};