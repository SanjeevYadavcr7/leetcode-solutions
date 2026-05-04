class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int currTime = 0;
        vector<int> freq(26, 0);
        priority_queue<int> maxHeap;
        queue<pair<int, int>> tasksQueue; // {remaning_freq, min next execution time}

        for(const char& ch : tasks) freq[ch - 'A']++;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) maxHeap.push(freq[i]); // push frequency of tasks in max heap
        }

        while(!maxHeap.empty() || !tasksQueue.empty()) {
            if(!tasksQueue.empty()) {
                int taskStartTime = tasksQueue.front().second;
                if(currTime >= taskStartTime) {
                    maxHeap.push(tasksQueue.front().first); // push task frequency
                    tasksQueue.pop();
                }
            }

            if(!maxHeap.empty()) {
                int maxTaskFreq = maxHeap.top();
                maxHeap.pop();
                maxTaskFreq--;
                if(maxTaskFreq > 0) {
                    tasksQueue.push({maxTaskFreq, currTime + n + 1});
                }
            }
            currTime++;
        }
        return currTime;
    }
};
