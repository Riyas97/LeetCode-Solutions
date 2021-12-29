class Twitter {
public:
    // to store follow
    unordered_map <int, unordered_set<int>> m;
    unordered_map <int, int> tweets;
    vector <int> t;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[tweetId] = userId;
        t.push_back(tweetId);
        
    }
    
    vector<int> getNewsFeed(int userId) {
        vector <int> ans;
        int num = 0;
        for (int i = t.size()-1; i >= 0; i--) {
            if (tweets[t[i]] == userId || 
                m[userId].find(tweets[t[i]]) != m[userId].end()) {
                ans.push_back(t[i]);
                num++;
            }
            if (num == 10) {
                break;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (m.find(followerId) == m.end()) {
            unordered_set <int> us;
            us.insert(followeeId);
            m[followerId] = us;
        } else {
            m[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (m.find(followerId) == m.end()) {
            return;
        } else {
            if (m[followerId].find(followeeId) == 
                m[followerId].end()) {
                return;
            } else {
                m[followerId].erase(followeeId);
            }
        }
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