class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;

        vector<int> dp(high + 1, 0);

        dp[0] = 1;

        int ans = 0;

        for (int i = 0; i <= high; i++) {

            if (i >= low) {
                ans = (ans + dp[i]) % MOD;
            }

            if (i + zero <= high) {
                dp[i + zero] = (dp[i + zero] + dp[i]) % MOD;
            }

            if (i + one <= high) {
                dp[i + one] = (dp[i + one] + dp[i]) % MOD;
            }
        }

        return ans;
    }
};