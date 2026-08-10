class Solution {
public:
    int findContentChildren(vector<int>& players, vector<int>& trainers) {
        int total_players = players.size();
        int total_trainers = trainers.size();

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int p = 0, t = 0;
        int cnt = 0;

        while(p < total_players && t < total_trainers) {
            if(players[p] <= trainers[t]) {
                p++;
                cnt++;
            }
            t++;
        }
        
        return cnt;
    }
};
