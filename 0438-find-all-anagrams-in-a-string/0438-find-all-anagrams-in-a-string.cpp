class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (p.size() > s.size()) {
            return ans;
        }

        vector<int> pCount(26, 0);
        vector<int> window(26, 0);

        // Frequency of p
        for (char ch : p) {
            pCount[ch - 'a']++;
        }

        int k = p.size();

        for (int i = 0; i < s.size(); i++) {

            // Add current character
            window[s[i] - 'a']++;

            // Remove left character
            if (i >= k) {

                window[s[i - k] - 'a']--;
            }

            // Compare frequencies
            if (window == pCount) {

                ans.push_back(i - k + 1);
            }
        }

        return ans;
    }
};