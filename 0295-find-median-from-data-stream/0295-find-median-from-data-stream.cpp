class MedianFinder {
public:

    // Max heap for smaller half
    priority_queue<int> leftHeap;

    // Min heap for larger half
    priority_queue<int,
                   vector<int>,
                   greater<int>> rightHeap;

    MedianFinder() {
    }

    void addNum(int num) {

        leftHeap.push(num);

        // Ensure all left values <= right values
        rightHeap.push(leftHeap.top());
        leftHeap.pop();

        // Balance heaps
        if (rightHeap.size() > leftHeap.size()) {

            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
    }

    double findMedian() {

        if (leftHeap.size() > rightHeap.size()) {

            return leftHeap.top();
        }

        return (leftHeap.top() +
                rightHeap.top()) / 2.0;
    }
};