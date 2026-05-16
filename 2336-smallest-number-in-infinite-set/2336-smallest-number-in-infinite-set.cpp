class SmallestInfiniteSet {
public:
    int current;

    // Min-heap for added back numbers
    priority_queue<int, vector<int>, greater<int>> pq;

    // To avoid duplicates in heap
    unordered_set<int> st;

    SmallestInfiniteSet() {
        current = 1;
    }
    
    int popSmallest() {

        // If heap has smaller available number
        if (!pq.empty()) {
            int num = pq.top();
            pq.pop();

            st.erase(num);

            return num;
        }

        // Otherwise return next infinite number
        return current++;
    }
    
    void addBack(int num) {

        // Only add if already removed
        // and not already present in heap
        if (num < current && st.find(num) == st.end()) {
            pq.push(num);
            st.insert(num);
        }
    }
};