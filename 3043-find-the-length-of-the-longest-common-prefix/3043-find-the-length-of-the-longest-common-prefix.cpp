class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1,
                            vector<int>& arr2) {

        unordered_set<string> prefixes;

        // Store all prefixes of arr1 numbers
        for (int num : arr1) {

            string s = to_string(num);
            string prefix = "";

            for (char ch : s) {

                prefix += ch;
                prefixes.insert(prefix);
            }
        }

        int maxLen = 0;

        // Check prefixes of arr2 numbers
        for (int num : arr2) {

            string s = to_string(num);
            string prefix = "";

            for (char ch : s) {

                prefix += ch;

                if (prefixes.count(prefix)) {
                    maxLen = max(maxLen,
                                 (int)prefix.length());
                }
            }
        }

        return maxLen;
    }
};