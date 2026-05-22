class Solution {
public:

    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {

            // If digit is less than 9
            if (digits[i] < 9) {

                digits[i]++;
                return digits;
            }

            // Carry case
            digits[i] = 0;
        }

        // If all digits were 9
        digits.insert(digits.begin(), 1);

        return digits;
    }
};