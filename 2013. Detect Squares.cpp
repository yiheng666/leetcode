class DetectSquares {
public:
    unordered_map<int,unordered_map<int,int>> mp;
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        mp[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x = point[0],y = point[1];
        int res = 0;
        for (auto [h,n] : mp[x]){
            int dist = y - h;
            if (dist){
                res += (mp[x+dist][h]*mp[x+dist][y] + mp[x-dist][h]*mp[x-dist][y]) * n;
            }
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */