class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string,vector<pair<int,string>>>mp;
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end())return "";
        auto vec=mp[key];
        int size=vec.size();
        int l=0;
        int r=size-1;
        pair<int,string> soln;
        string ans;
        while(l<=r){
            int mid=(l+r)/2;
            pair<int,string> soln=vec[mid];
            if(soln.first==timestamp)return soln.second;
            if(soln.first<timestamp){
                ans=soln.second;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;

    }
};
