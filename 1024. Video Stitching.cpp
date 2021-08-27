class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        if (a[0] != b[0]) return a[0] < b[0];
        else return a[1] > b[1]; 
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size(),count = 0,i = 0;
        sort(clips.begin(),clips.end(),cmp);
        int cur_end = 0,next_end = 0;
        while (i < n && clips[i][0] <= cur_end){
            while (i < n && clips[i][0] <= cur_end){
                next_end = max(next_end,clips[i][1]);
                i++;
            }
            count++;
            cur_end = next_end;
            if (cur_end >= time) return count;
        }
        return -1;
    }
};

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> dp(time+1,time+1);
        dp[0] = 0;
        for (int i=1;i<=time;i++){
            for (auto clip : clips){
                if (clip[0] <= i && clip[1] >= i)
                    dp[i] = min(dp[i],dp[clip[0]]+1);
            }
        }
        return dp[time] == time+1 ? -1 : dp[time];
    }
};