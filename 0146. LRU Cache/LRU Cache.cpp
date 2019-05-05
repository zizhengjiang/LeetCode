class LRUCache {
    int capacity;
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> um;
public:
    LRUCache(int capacity) : capacity{capacity} {}
    
    int get(int key) {
        if (um.find(key) == um.end())
            return -1;
        li.splice(li.begin(), li, um[key]);
        return um[key]->second;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            um[key]->second = value;
        } else {
            if (um.size() == capacity) {
                int delKey = li.back().first;
                li.pop_back();
                um.erase(delKey);
            }
            li.emplace_front(key, value);
            um[key] = li.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */