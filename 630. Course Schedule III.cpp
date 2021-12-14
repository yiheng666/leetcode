class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size(),cur = 0;
        sort(courses.begin(),courses.end(),cmp);
        priority_queue<int> q;
        for (int i=0;i<n;i++){
            if (courses[i][0] + cur <= courses[i][1]){
                cur += courses[i][0];
                q.push(courses[i][0]);
                continue;
            }
            //用时短且结束时间较后的课程一定可以替代在q中的课程
            if (!q.empty() && q.top() > courses[i][0]){
                cur -= q.top();
                cur += courses[i][0];
                q.pop();
                q.push(courses[i][0]);
            }
        }
        return q.size();
    }
};