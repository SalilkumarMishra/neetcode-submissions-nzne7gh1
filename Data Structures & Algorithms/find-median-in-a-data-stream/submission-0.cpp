#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // left (smaller half)
    priority_queue<int, vector<int>, greater<int>> minHeap; // right (larger half)

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // Step 1: Add to maxHeap
        maxHeap.push(num);
        
        // Step 2: Ensure ordering property
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        // Step 3: Balance sizes
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};