class Solution {
public:

    vector<string> ans;

    void backtrack(int open,
                   int close,
                   int n,
                   string current) {

        // Valid combination formed
        if (current.size() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Add opening bracket
        if (open < n) {
            backtrack(open + 1,
                      close,
                      n,
                      current + "(");
        }

        // Add closing bracket
        if (close < open) {
            backtrack(open,
                      close + 1,
                      n,
                      current + ")");
        }
    }

    vector<string> generateParenthesis(int n) {

        backtrack(0, 0, n, "");

        return ans;
    }
};