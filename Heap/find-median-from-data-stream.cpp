class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {}
    
    void addNum(int num) {
        minHeap.push(num);
        num = minHeap.top();  // remove min element
        minHeap.pop(); 
        maxHeap.push(num);  // push minimum element to max heap to maintain increasing order
        if(maxHeap.size() > minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        int totalNums = maxHeap.size() + minHeap.size();
        double median = totalNums & 1 
                        ? double(minHeap.top()) // if total nums are odd, then top of min heap has mid element
                        : double(minHeap.top() + maxHeap.top()) / 2.0;
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
