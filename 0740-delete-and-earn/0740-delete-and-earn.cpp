class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> points(10001, 0);

        for (int num : nums) {
            points[num] += num;
        }

        int take = 0, skip = 0;

        for (int i = 0; i <= 10000; i++) {
            int takei = skip + points[i];
            int skipi = max(skip, take);

            take = takei;
            skip = skipi;
        }

        return max(take, skip);
    }
};