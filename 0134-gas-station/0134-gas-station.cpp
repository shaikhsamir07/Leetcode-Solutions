class Solution {
public:
    int canCompleteCircuit(vector<int>& gas,
                           vector<int>& cost) {

        int totalGas = 0;
        int currentGas = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++) {

            int diff = gas[i] - cost[i];

            totalGas += diff;
            currentGas += diff;

            // Cannot reach next station
            if (currentGas < 0) {

                start = i + 1;
                currentGas = 0;
            }
        }

        // Total gas must be enough
        return (totalGas >= 0) ? start : -1;
    }
};