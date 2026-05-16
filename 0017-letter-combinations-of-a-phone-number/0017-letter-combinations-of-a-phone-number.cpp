class Solution {
public:
    
    vector<string> ans;

    void backtrack(string& digits,
                   int index,
                   string& current,
                   vector<string>& mapping) {

        // Complete combination formed
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char ch : letters) {
            current.push_back(ch);

            backtrack(digits, index + 1, current, mapping);

            // Backtrack
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty()) {
            return {};
        }

        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string current = "";

        backtrack(digits, 0, current, mapping);

        return ans;
    }
};