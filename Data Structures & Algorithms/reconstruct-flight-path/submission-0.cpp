class Solution {
public:
    unordered_map<
        string,
        priority_queue<string, vector<string>, greater<string>>
    > mp;
    
    vector<string> ans;

    void dfs(string curr){
        while(!mp[curr].empty()){
            string str = mp[curr].top();
            mp[curr].pop();
            dfs(str);
        }
        ans.push_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i=0;i<tickets.size();i++){
            mp[tickets[i][0]].push(tickets[i][1]);
        }

        dfs("JFK");

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

