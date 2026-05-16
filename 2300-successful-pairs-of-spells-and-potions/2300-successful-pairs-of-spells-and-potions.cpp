class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells,
                                vector<int>& potions,
                                long long success) {

        sort(potions.begin(), potions.end());

        int m = potions.size();

        vector<int> ans;

        for (int spell : spells) {

            long long need =
                (success + spell - 1) / spell;

            // First potion >= need
            int idx = lower_bound(potions.begin(),
                                  potions.end(),
                                  need) - potions.begin();

            ans.push_back(m - idx);
        }

        return ans;
    }
};