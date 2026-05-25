class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<bool> reachable(n, false);
        reachable[0] = true;

        int farthest = 0;

        for (int i = 0; i < n; i++) {
            if (!reachable[i])
                continue;

            int start = max(i + minJump, farthest + 1);
            int end = min(i + maxJump, n - 1);

            for (int j = start; j <= end; j++) {
                if (s[j] == '0') {
                    reachable[j] = true;
                }
            }

            farthest = end;
        }

        return reachable[n - 1];
    }
};