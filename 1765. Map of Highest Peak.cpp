class Solution {
public:
    const int shift = 1024;
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        unordered_map<int,bool> visited;
        queue<pair<int,int>> q;
        vector<int> dir = {-1,0,1,0,-1};
        int m = isWater.size(),n = isWater[0].size();
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (isWater[i][j] == 1){
                    visited[i*shift+j] = true;
                    q.push({i*shift+j,0});
                    isWater[i][j] = 0;
                }
            }
        }
        while (!q.empty()){
            int num = q.front().first,level=q.front().second+1;q.pop();
            visited[num] = true;
            int x = num / shift,y = num % shift;
            for (int i=0;i<4;i++){
                int tempX = x + dir[i],tempY = y + dir[i+1];
                if (tempX < 0 || tempX >= m || tempY < 0 || tempY >= n) continue;
                if (!visited[tempX*shift+tempY]){
                    visited[tempX*shift+tempY] = true;
                    q.push({tempX*shift+tempY,level});
                    isWater[tempX][tempY] = level;
                }
            }
        }
        return isWater;
    }
};