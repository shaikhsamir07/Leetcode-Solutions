class Solution {
public:
    long long countSteps(long long curr, long long next, long long n) {

        long long steps = 0;

        while (curr <= n) {

            steps += min(n + 1LL, next) - curr;

            curr *= 10;
            next *= 10;
        }

        return steps;
    }

    int findKthNumber(int n, int k) {

        long long curr = 1;

        k--;

        while (k > 0) {

            long long steps = countSteps(curr, curr + 1, n);

            if (steps <= k) {

                curr++;

                k -= steps;

            } else {

                curr *= 10;

                k--;
            }
        }

        return curr;
    }
};