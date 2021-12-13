class TopVotedCandidate {
    //vote记录每个人的票数， win[t]记录t时刻的获胜者
    map<int, int> vote, win;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times){
        vote[persons[0]] ++;
        int last = win[times[0]] = persons[0];
        for (int i = 1, n = times.size(); i < n; ++ i)
            if (++ vote[persons[i]] >= vote[last])
                win[times[i]] = last = persons[i];
    }
    //win中键值<t时刻的获胜者即为t时刻的获胜者
    int q(int t) {
        return prev(win.upper_bound(t))->second;
    }
};