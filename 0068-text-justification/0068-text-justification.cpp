class Solution {
public:
    vector<string> fullJustify(vector<string>& words,
                               int maxWidth) {

        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {

            int lineLength = words[i].length();
            int j = i + 1;

            // Find how many words fit in current line
            while (j < n &&
                   lineLength + 1 + words[j].length()
                   <= maxWidth) {

                lineLength += 1 + words[j].length();
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            // Last line OR single word line
            if (j == n || gaps == 0) {

                for (int k = i; k < j; k++) {

                    line += words[k];

                    if (k != j - 1) {
                        line += " ";
                    }
                }

                // Fill remaining spaces
                while (line.length() < maxWidth) {
                    line += " ";
                }
            }
            else {

                int totalChars = 0;

                for (int k = i; k < j; k++) {
                    totalChars += words[k].length();
                }

                int totalSpaces = maxWidth - totalChars;

                int evenSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; k++) {

                    line += words[k];

                    if (k != j - 1) {

                        int spaces = evenSpaces;

                        // Left slots get extra spaces
                        if (extraSpaces > 0) {
                            spaces++;
                            extraSpaces--;
                        }

                        line += string(spaces, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};