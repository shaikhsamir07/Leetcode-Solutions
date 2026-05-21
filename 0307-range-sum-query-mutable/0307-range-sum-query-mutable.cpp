class NumArray {
public:
    vector<int> segTree;
    vector<int> nums;
    int n;

    NumArray(vector<int>& nums) {

        this->nums = nums;
        n = nums.size();

        segTree.resize(4 * n);

        build(0, 0, n - 1);
    }

    void build(int idx, int low, int high) {

        if (low == high) {
            segTree[idx] = nums[low];
            return;
        }

        int mid = (low + high) / 2;

        build(2 * idx + 1, low, mid);
        build(2 * idx + 2, mid + 1, high);

        segTree[idx] = segTree[2 * idx + 1] +
                       segTree[2 * idx + 2];
    }

    void updateHelper(int idx, int low, int high,
                      int i, int val) {

        if (low == high) {
            segTree[idx] = val;
            return;
        }

        int mid = (low + high) / 2;

        if (i <= mid)
            updateHelper(2 * idx + 1, low, mid, i, val);
        else
            updateHelper(2 * idx + 2, mid + 1, high, i, val);

        segTree[idx] = segTree[2 * idx + 1] +
                       segTree[2 * idx + 2];
    }

    int query(int idx, int low, int high,
              int l, int r) {

        if (r < low || high < l)
            return 0;

        if (l <= low && high <= r)
            return segTree[idx];

        int mid = (low + high) / 2;

        return query(2 * idx + 1, low, mid, l, r) +
               query(2 * idx + 2, mid + 1, high, l, r);
    }

    void update(int index, int val) {

        updateHelper(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {

        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */