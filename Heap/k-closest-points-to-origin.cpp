using customPair = pair<int, pair<int, int>>;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> kClosestPoints;
        priority_queue<customPair, vector<customPair>, greater<customPair>> minHeap;

        for(auto& point : points) {
            int d = point[0] * point[0] + point[1] * point[1];
            minHeap.push({d, {point[0], point[1]}});
        }

        while(k--) {
            customPair point = minHeap.top();
            minHeap.pop();
            kClosestPoints.push_back({point.second.first, point.second.second});
        }
        return kClosestPoints;
    }
};
