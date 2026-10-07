class LRUCache {
public:

    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;

        auto iter = m[key];
        int val = iter->second;
        cache.splice(cache.begin(), cache, iter);
        return val;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end())
        {
            auto iter = m[key];
            iter->second = value;
            cache.splice(cache.begin(), cache, iter);
            return;
        }

        cache.push_front({key, value});
        m[key] = cache.begin();

        if(cache.size() > capacity)
        {
            auto last = cache.end();
            --last;

            m.erase(last->first);

            cache.pop_back();
        }
    }
};
