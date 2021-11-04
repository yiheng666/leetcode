class Solution {
public:
    using PII = pair<int, int>;
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        int ans = 0;
        auto cmp = [&](const PII& p1, const PII& p2) {
            auto [x1, y1] = p1;
            auto [x2, y2] = p2;
            return heightMap[x1][y1] > heightMap[x2][y2];
        };
        priority_queue<PII, vector<PII>, decltype(cmp)> qu(cmp);
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            qu.emplace(i, 0);
            qu.emplace(i, n - 1);
            seen[i][0] = seen[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; ++j) {
            qu.emplace(0, j);
            qu.emplace(m - 1, j);
            seen[0][j] = seen[m - 1][j] = true;
        }
        while (!qu.empty()) {
            auto [r, c] = qu.top(); qu.pop();
            int h = heightMap[r][c];
            for (int i = 0; i < 4; ++i) {
                int x = r + dx[i], y = c + dy[i];
                if (x < 0 || x >= m || y < 0 || y >= n || seen[x][y]) {
                    continue;
                }
                if (h > heightMap[x][y]) {
                    ans += h - heightMap[x][y];
                    heightMap[x][y] = h;
                }
                qu.emplace(x, y);
                seen[x][y] = true;
            }
        }
        return ans;
    }
private:
    static constexpr int dx[4] = { 0, 1, 0, -1 };
    static constexpr int dy[4] = { 1, 0, -1, 0 };
};