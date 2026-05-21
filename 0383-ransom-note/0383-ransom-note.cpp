class Solution {
public:
    bool canConstruct(string ransomNote,
                      string magazine) {

        vector<int> freq(26, 0);

        // Count letters in magazine
        for (char c : magazine) {

            freq[c - 'a']++;
        }

        // Use letters for ransomNote
        for (char c : ransomNote) {

            freq[c - 'a']--;

            // Not enough letters
            if (freq[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};