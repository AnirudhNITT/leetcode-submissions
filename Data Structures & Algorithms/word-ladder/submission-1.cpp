class Solution {
public:
    bool is_true(string s1,string s2){
        int diff=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])diff++;
        }
        if(diff==1)return true;
        return false;
    }
    unordered_map<string,vector<string>> build_adj(vector<string>& wl,string beginWord){
        unordered_map<string,vector<string>>adj;
        for(auto i : wl){
            for(auto j: wl){
                if(is_true(i,j))adj[i].push_back(j);
            }
            if(is_true(beginWord,i)) adj[beginWord].push_back(i);
        }
        return adj;
    }
    int bfs(int size,unordered_map<string,vector<string>>&adj,string start,string end,unordered_map<string,bool>&visit){
        queue<string>q;
        int count_iter=1;
        q.push(start);
        visit[start]=true;
        while(!q.empty()){
            int curr_q=q.size();
            while(curr_q>0){
                auto top=q.front();
                q.pop();
                for(auto word : adj[top]){
                    if(visit[word])continue;
                    if(word==end)return count_iter+1;
                    q.push(word);
                    visit[word]=true;  
                }
                curr_q--;
            
            if(count_iter>size+1)return 0;
            }
            count_iter++;
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool>visit;
        for(auto word : wordList){
            visit[word]=false;
        }
        unordered_map<string,vector<string>>adj=build_adj(wordList,beginWord);
        return bfs(wordList.size(),adj,beginWord,endWord,visit);
        
    }
};
