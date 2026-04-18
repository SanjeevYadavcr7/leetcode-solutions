    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1) return intervals;

        int start, end;
        vector<vector<int>> mergedIntervals;

        sort(intervals.begin(), intervals.end());  // sort wrt starting time
        
        start = intervals[0][0], end= intervals[0][1];
        for(int i = 0; i < n; i++) {
            int curr_start = intervals[i][0];
            if(curr_start <= end) {
                end = max(end, intervals[i][1]);
            } else {
                mergedIntervals.push_back({start, end});
                start = curr_start, end = intervals[i][1];
            }
        }
        mergedIntervals.push_back({start, end});
        return mergedIntervals;
    }
