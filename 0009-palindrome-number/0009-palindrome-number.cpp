class Solution {
public:

    bool isPalindrome(int x) {

        // Negative numbers are not palindrome
        // Numbers ending with 0 (except 0) are not palindrome
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversed = 0;

        // Reverse only half of the number
        while (x > reversed) {

            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // Even digits: x == reversed
        // Odd digits: x == reversed / 10
        return (x == reversed || x == reversed / 10);
    }
};