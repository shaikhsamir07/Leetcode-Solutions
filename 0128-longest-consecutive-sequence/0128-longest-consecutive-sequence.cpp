class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(),
                              nums.end());

        int longest = 0;

        for (int num : st) {

            // Start of sequence
            if (!st.count(num - 1)) {

                int currentNum = num;
                int length = 1;

                // Count consecutive numbers
                while (st.count(currentNum + 1)) {

                    currentNum++;
                    length++;
                }

                longest = max(longest,
                              length);
            }
        }

        return longest;
    }
};