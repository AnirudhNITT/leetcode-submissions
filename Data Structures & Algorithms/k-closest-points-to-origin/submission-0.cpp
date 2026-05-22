class Solution {
public:
    struct cmp{
        bool operator()(vector<int>p1,vector<int>p2){
            int a = p1[0]*p1[0] + p1[1]*p1[1];
            int b = p2[0]*p2[0] + p2[1]*p2[1];
            return a>=b ;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,cmp>pq;
        for(auto it :points){
            pq.push(it);
        }
        vector<vector<int>>soln;
        for(int i=0;i<k;i++){
            soln.push_back(pq.top());
            pq.pop();
        }
        return soln;
    }
};
