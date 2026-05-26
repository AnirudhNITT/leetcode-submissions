class CountSquares {
public:
    unordered_map<int,unordered_map<int,int>> mp;
    vector<vector<int>> pts;
    void add(vector<int> point) {
        mp[point[0]][point[1]]++;
        pts.push_back(point);
    }
    int count(vector<int> point) {
        int x=point[0];
        int y=point[1];
        int ans=0;
        for(auto it:pts){
            int nx=it[0];
            int ny=it[1];
            if(abs(nx-x)!=abs(ny-y) || nx==x || ny==y) continue;
            ans+=mp[x][ny]*mp[nx][y];
        }
        return ans;
    }
};