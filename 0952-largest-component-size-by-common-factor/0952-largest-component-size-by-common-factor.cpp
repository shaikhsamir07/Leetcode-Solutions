class Solution {
public:

    vector<int> parent;
    vector<int> size;

    int find(int x) {

        if (parent[x] == x) {
            return x;
        }

        return parent[x] =
               find(parent[x]);
    }

    void unite(int x, int y) {

        int px = find(x);
        int py = find(y);

        if (px == py) {
            return;
        }

        // Union by size
        if (size[px] < size[py]) {
            swap(px, py);
        }

        parent[py] = px;
        size[px] += size[py];
    }

    int largestComponentSize(vector<int>& nums) {

        int maxNum =
            *max_element(nums.begin(),
                         nums.end());

        parent.resize(maxNum + 1);
        size.resize(maxNum + 1, 1);

        for (int i = 0;
             i <= maxNum;
             i++) {

            parent[i] = i;
        }

        // Connect number with its factors
        for (int num : nums) {

            for (int factor = 2;
                 factor * factor <= num;
                 factor++) {

                if (num % factor == 0) {

                    unite(num, factor);
                    unite(num,
                          num / factor);
                }
            }
        }

        unordered_map<int, int> count;
        int result = 0;

        // Count component sizes
        for (int num : nums) {

            int root = find(num);

            count[root]++;

            result = max(result,
                         count[root]);
        }

        return result;
    }
};