class MapSum {
public:
    unordered_map<string,int> Map;
    MapSum() {
    }
    
    void insert(string key, int val) {
        Map[key] = val;
    }
    
    int sum(string prefix) {
        int res = 0;
        for (auto it : Map){
            string s = it.first;
            if (s.find(prefix) == 0){
                res += it.second;
            }
        }
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */