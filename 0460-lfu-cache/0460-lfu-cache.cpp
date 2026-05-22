class LFUCache {
public:

    struct Node {
        int value;
        int freq;
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node> keyTable;

    unordered_map<int, list<int>> freqTable;

    unordered_map<int, list<int>::iterator> position;

    LFUCache(int capacity) {

        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(int key) {

        int freq = keyTable[key].freq;

        // Remove key from old frequency list
        freqTable[freq].erase(position[key]);

        // If old freq list becomes empty
        if (freqTable[freq].empty()) {

            freqTable.erase(freq);

            if (minFreq == freq) {
                minFreq++;
            }
        }

        // Increase frequency
        keyTable[key].freq++;

        freq++;

        // Add key to new frequency list
        freqTable[freq].push_front(key);

        position[key] = freqTable[freq].begin();
    }

    int get(int key) {

        if (keyTable.find(key) == keyTable.end()) {

            return -1;
        }

        updateFreq(key);

        return keyTable[key].value;
    }

    void put(int key, int value) {

        if (capacity == 0)
            return;

        // Key already exists
        if (keyTable.find(key) != keyTable.end()) {

            keyTable[key].value = value;

            updateFreq(key);

            return;
        }

        // Cache full
        if (keyTable.size() == capacity) {

            int evictKey = freqTable[minFreq].back();

            freqTable[minFreq].pop_back();

            if (freqTable[minFreq].empty()) {

                freqTable.erase(minFreq);
            }

            keyTable.erase(evictKey);

            position.erase(evictKey);
        }

        // Insert new key
        keyTable[key] = {value, 1};

        freqTable[1].push_front(key);

        position[key] = freqTable[1].begin();

        minFreq = 1;
    }
};