class LRUCache {
public:
    int maxCapacity;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> ls;
    LRUCache(int capacity) {
        this->maxCapacity = capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if (it != mp.end()){
            ls.splice(ls.begin(),ls,it->second);
            return it->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()){
            ls.splice(ls.begin(),ls,it->second);
            it->second->second = value;
            return;
        }
        ls.emplace_front(key,value);
        mp[key] = ls.begin();
        if (mp.size() > maxCapacity){
            mp.erase(ls.back().first);
            ls.pop_back();
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */