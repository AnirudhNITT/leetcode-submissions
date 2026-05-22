class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> hash;
    unordered_map<int,unordered_set<int>> following;
    int timer;
    Twitter() {
        timer=0;
    }
    void postTweet(int userId, int tweetId) {
        hash[userId].push_back({timer++,tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;

        for(auto x:hash[userId]){
            pq.push(x);
        }
        for(auto f:following[userId]){
            for(auto x:hash[f]){
                pq.push(x);
            }
        }
        vector<int> soln;
        int k=0;
        while(!pq.empty() && k<10){
            soln.push_back(pq.top().second);
            pq.pop();
            k++;
        }
        return soln;
    }
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            following[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};