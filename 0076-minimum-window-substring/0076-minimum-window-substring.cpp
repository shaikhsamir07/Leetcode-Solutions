class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> need(128, 0);

        for (char ch : t) {
            need[ch]++;
        }

        int left = 0;
        int count = t.size();

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            // Character needed
            if (need[s[right]] > 0) {
                count--;
            }

            need[s[right]]--;

            // Valid window found
            while (count == 0) {

                // Update minimum window
                if (right - left + 1 < minLen) {

                    minLen = right - left + 1;

                    start = left;
                }

                need[s[left]]++;

                // Window becomes invalid
                if (need[s[left]] > 0) {
                    count++;
                }

                left++;
            }
        }

        return (minLen == INT_MAX)
               ? ""
               : s.substr(start, minLen);
    }
};