class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> words;
        string word;

        stringstream ss(s);

        // Split string into words
        while (ss >> word) {
            words.push_back(word);
        }

        // Length mismatch
        if (pattern.length() != words.size()) {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.length(); i++) {

            char c = pattern[i];
            string w = words[i];

            // Check char -> word mapping
            if (charToWord.count(c) &&
                charToWord[c] != w) {

                return false;
            }

            // Check word -> char mapping
            if (wordToChar.count(w) &&
                wordToChar[w] != c) {

                return false;
            }

            charToWord[c] = w;
            wordToChar[w] = c;
        }

        return true;
    }
};