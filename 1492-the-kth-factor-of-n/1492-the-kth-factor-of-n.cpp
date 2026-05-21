class Solution {
public:
    int kthFactor(int n, int k) {

        vector<int> largeFactors;

        for (int i = 1; i * i <= n; i++) {

            if (n % i == 0) {

                k--;

                if (k == 0)
                    return i;

                if (i != n / i) {
                    largeFactors.push_back(n / i);
                }
            }
        }

        reverse(largeFactors.begin(), largeFactors.end());

        for (int factor : largeFactors) {

            k--;

            if (k == 0)
                return factor;
        }

        return -1;
    }
};