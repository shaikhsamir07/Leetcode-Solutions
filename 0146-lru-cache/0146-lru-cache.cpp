class LRUCache {
public:

    int capacity;

    list<pair<int, int>> cache;

    unordered_map<int,
                  list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {

        this->capacity = capacity;
    }

    int get(int key) {

        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // Move accessed node to front
        auto node = mp[key];

        int value = node->second;

        cache.erase(node);

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

        // Remove LRU item
        if (cache.size() > capacity) {

            auto last = cache.back();

            mp.erase(last.first);

            cache.pop_back();
        }
    }
};