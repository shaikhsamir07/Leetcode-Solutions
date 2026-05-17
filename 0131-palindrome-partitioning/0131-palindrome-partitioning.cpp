class Solution {
public:

    vector<vector<string>> ans;

    bool isPalindrome(string& s, int left, int right) {

        while (left < right) {

            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    void backtrack(string& s,
                   int start,
                   vector<string>& current) {

        // Valid partition formed
        if (start == s.size()) {
            ans.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); end++) {

            // Check palindrome
            if (isPalindrome(s, start, end)) {

                current.push_back(s.substr(start,
                                           end - start + 1));

                backtrack(s, end + 1, current);

                // Backtrack
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> current;

        backtrack(s, 0, current);

        return ans;
    }
};