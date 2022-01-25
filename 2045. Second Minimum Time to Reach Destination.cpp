class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        //先中出单源最短路径
        vector<int> visited(n, 2);
        queue<int> q;
        vector<vector<int>> m(n, vector<int>());
        vector<int> log(n, -1);//防止节点重复添加

        //保存边
        for(auto edge: edges){
            m[edge[0] - 1].push_back(edge[1] - 1);
            m[edge[1] - 1].push_back(edge[0] - 1);
        }
        
        q.push(0);
        --visited[0];
        int t = 0;
        int first = -1;
        while (!q.empty()) {
            int qsize = q.size();
            if(t / change % 2 == 1)
                t += change - t % change;
            t += time;
            while (qsize-- > 0) {
                int idx = q.front();
                q.pop();
                for (int i = 0; i < m[idx].size(); ++i) {
                    if(t <= log[m[idx][i]] || visited[m[idx][i]] == 0)
                        continue;
                    --visited[m[idx][i]];
                    log[m[idx][i]] = t;
                    q.push(m[idx][i]);
                    if (m[idx][i] == n - 1) {
                        if(first == -1){
                            first = t;
                            continue;
                        }
                        else
                            return t;
                    }
                }
            }
        }
        return 0;
    }
};