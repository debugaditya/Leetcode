class LRUCache {
public:
    int cap;
    list<pair<int,int>> dll;  
    unordered_map<int, list<pair<int,int>>::iterator> mp;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if(mp.count(key) == 0) return -1;

        // move accessed node to front
        auto it = mp[key];
        int val = it->second;
        dll.erase(it);
        dll.push_front({key, val});
        mp[key] = dll.begin();

        return val;
    }

    void put(int key, int value) {
        // key already exists
        if(mp.count(key)) {
            dll.erase(mp[key]);
        }
        else if(dll.size() == cap) {
            // remove LRU
            auto lru = dll.back();
            mp.erase(lru.first);
            dll.pop_back();
        }

        // insert as MRU
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};

