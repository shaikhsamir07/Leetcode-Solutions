class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> lastSeen(256, -1);

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {

            char ch = s[right];

            // If character already exists in current window
            if (lastSeen[ch] >= left) {

                left = lastSeen[ch] + 1;
            }

            lastSeen[ch] = right;

            maxLen = max(maxLen,
                         right - left + 1);
        }

        return maxLen;
    }
};