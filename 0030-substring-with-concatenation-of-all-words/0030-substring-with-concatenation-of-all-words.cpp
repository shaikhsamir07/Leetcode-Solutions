class Solution {
public:
    vector<int> findSubstring(string s,
                              vector<string>& words) {

        vector<int> result;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> wordMap;

        for (string word : words) {
            wordMap[word]++;
        }

        // Try every possible starting offset
        for (int offset = 0;
             offset < wordLen;
             offset++) {

            int left = offset;
            int count = 0;

            unordered_map<string, int> window;

            for (int right = offset;
                 right + wordLen <= s.length();
                 right += wordLen) {

                string word =
                    s.substr(right, wordLen);

                // Valid word
                if (wordMap.count(word)) {

                    window[word]++;
                    count++;

                    // Too many occurrences
                    while (window[word] >
                           wordMap[word]) {

                        string leftWord =
                            s.substr(left, wordLen);

                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // Found valid window
                    if (count == wordCount) {

                        result.push_back(left);

                        string leftWord =
                            s.substr(left, wordLen);

                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                }
                else {

                    // Reset window
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
    }
};