class Solution {
public:
    vector<int> partitionLabels(string s) {

        vector<int> lastIndex(26);

        // Store last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<int> ans;

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.size(); i++) {

            end = max(end,
                      lastIndex[s[i] - 'a']);

            // Partition found
            if (i == end) {

                ans.push_back(end - start + 1);

                start = i + 1;
            }
        }

        return ans;
    }
};