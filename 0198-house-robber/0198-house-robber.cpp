class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0; // Max till previous house
        int prev2 = 0; // Max till house before previous

        for (int money : nums) {
            int curr = max(prev1, prev2 + money);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};