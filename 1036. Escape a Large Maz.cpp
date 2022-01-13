class Solution {
public:
    int BoardLength = 1000000;
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        return bfs(blocked,source,target) && bfs(blocked,target,source);
    }
    bool bfs(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target){
        unordered_set<int> visited;
        for (auto block : blocked) visited.insert(block[0] * 131 + block[1]);
        visited.insert(source[0] * 131 + source[1]);
        queue<vector<int>> q;
        q.push(source);
        while (!q.empty()){
            int n = q.size();
            if (n >= blocked.size()) return true;
            while (n--){
                vector<int> temp = q.front();
                q.pop();
                for (int i=0;i<4;i++){
                    int x = temp[0] + dir[i][0], y = temp[1] + dir[i][1];
                    if (x<0 || y<0 || x>=BoardLength || y>=BoardLength) continue;
                    if (x == target[0] && y == target[1]) return true;
                    if (visited.count(x*131+y) == 0){
                        q.push({x,y});
                        visited.insert(x*131+y);
                    } 
                }
            }
        }
        return false;
    }
};