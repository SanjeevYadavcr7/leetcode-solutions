class KthLargest {
public:
    int kSize;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums) {
        kSize = k;
        for(int& num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > kSize) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
