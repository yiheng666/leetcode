class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string cur;
        int step = 0;
        for (int i=0;i<2;i++){
            for (int j=0;j<3;j++){
                cur += board[i][j] + '0';
            }
        }
        vector<vector<int>> dir{{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        queue<string> q;
        string target = "123450";
        unordered_set<string> visited;
        q.push(cur);
        visited.insert(cur);
        while (!q.empty()){
            int sz = q.size();
            for (int i=0;i<sz;i++){
                cur = q.front();
                q.pop();
                if (cur == target) return step;
                int index = 0;
                while (cur[index] != '0') index++;
                for (int adj : dir[index]){
                    string temp = cur;
                    swap(temp[adj],temp[index]);
                    if (!visited.count(temp)){
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};