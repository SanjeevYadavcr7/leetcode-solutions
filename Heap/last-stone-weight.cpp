class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        
        for(const int& num : stones) {
            maxHeap.push(num);
        }

        while(maxHeap.size() > 1) {
            int heaviest = maxHeap.top();
            maxHeap.pop();
            int second_heaviest = maxHeap.top();
            maxHeap.pop();

            maxHeap.push(heaviest - second_heaviest);
        }

        return maxHeap.top();
    }
};
