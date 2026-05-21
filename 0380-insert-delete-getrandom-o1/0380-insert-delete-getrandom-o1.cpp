class RandomizedSet {
public:

    vector<int> nums;
    unordered_map<int, int> mp;

    RandomizedSet() {

    }

    bool insert(int val) {

        // Already exists
        if (mp.count(val)) {
            return false;
        }

        nums.push_back(val);
        mp[val] = nums.size() - 1;

        return true;
    }

    bool remove(int val) {

        // Does not exist
        if (!mp.count(val)) {
            return false;
        }

        int index = mp[val];
        int lastElement = nums.back();

        // Move last element to deleted position
        nums[index] = lastElement;
        mp[lastElement] = index;

        // Remove last element
        nums.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() {

        int randomIndex = rand() % nums.size();

        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */