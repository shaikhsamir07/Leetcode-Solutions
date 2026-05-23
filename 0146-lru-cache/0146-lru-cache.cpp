class LRUCache {
public:
    int cap;

    // Doubly linked list stores {key, value}
    list<pair<int, int>> cache;

    // key -> iterator of list
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // Move accessed node to front
        auto it = mp[key];
        int value = it->second;

        cache.erase(it);
        cache.push_front({key, value});

        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {

        // If key already exists
        if (mp.find(key) != mp.end()) {
            cache.erase(mp[key]);
        }

        // Insert at front
        cache.push_front({key, value});
        mp[key] = cache.begin();

        // Remove LRU if capacity exceeded
        if (cache.size() > cap) {
            auto last = cache.back();

            mp.erase(last.first);
            cache.pop_back();
        }
    }
};