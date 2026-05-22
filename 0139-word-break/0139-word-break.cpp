class Solution {
public:
    int dp[301];

    bool solve(int idx,
               string& s,
               unordered_set<string>& st) {

        if (idx == s.size())
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        string temp = "";

        for (int i = idx; i < s.size(); i++) {

            temp += s[i];

            if (st.count(temp)) {

                if (solve(i + 1, s, st))
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st(wordDict.begin(),
                                 wordDict.end());

        memset(dp, -1, sizeof(dp));

        return solve(0, s, st);
    }
};