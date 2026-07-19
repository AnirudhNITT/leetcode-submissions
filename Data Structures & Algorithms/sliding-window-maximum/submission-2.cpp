class Solution {
public:
    vector<int>arr;
    vector<int>seg;
    void build(int idx,int l,int r){
        if(l==r){
            seg[idx]=arr[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*idx+1,l,mid);
        build(2*idx+2,mid+1,r);
        seg[idx]=max(seg[2*idx+2],seg[2*idx+1]);
    }
    int query(int low,int high,int l,int r,int idx){
        if(low>r || high<l)return INT_MIN;
        if(low<=l && r<=high)return seg[idx];
        int mid=(l+r)/2;
        return max(query(low,high,l,mid,(2*idx+1)),query(low,high,mid+1,r,(2*idx+2)));
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0;
        int r=k-1;
        int n=nums.size();
        vector<int>ans;
        arr=nums;
        seg.resize(4*n);
        build(0,0,n-1);
        while(r<nums.size()){
            ans.push_back(query(l,r,0,n-1,0));
            l++;
            r++;
        }
        return ans;
    }
};
