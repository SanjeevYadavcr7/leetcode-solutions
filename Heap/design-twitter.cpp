class Twitter {
private:
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followers;

public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq; // store tweets wrt timestamp i.e. latest post first

        vector<int> usersToCheck = {userId};
        if(followers.count(userId)) {
            for(int followeeId : followers[userId]) {
                usersToCheck.push_back(followeeId); // add user and people followed by given user
            }
        }

        for(const int& userId : usersToCheck) {
            if(tweets.count(userId)) {
                int totalTweets = tweets[userId].size();
                for(int i = max(0, totalTweets - 10); i < totalTweets; i++) {
                    pq.push(tweets[userId][i]); // adding tweets to maximum heap
                }
            }
        }

        vector<int> feed;
        while(!pq.empty() && feed.size() < 10) {
            feed.push_back(pq.top().second); // getting latest 10 tweets
            pq.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
