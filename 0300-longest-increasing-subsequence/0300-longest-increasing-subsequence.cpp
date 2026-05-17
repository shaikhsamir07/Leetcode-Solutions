class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> temp;

        for (int num : nums) {

            auto it = lower_bound(temp.begin(),
                                  temp.end(),
                                  num);

            // Extend LIS
            if (it == temp.end()) {
                temp.push_back(num);
            }
            // Replace element
            else {
                *it = num;
            }
        }

        return temp.size();
    }
};