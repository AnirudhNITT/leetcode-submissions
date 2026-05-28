class Solution {
public:
    void merge(vector<int> &nums,int l,int r){
        vector<int> temp;
        int mid=(l+r)/2;
        int i=l;
        int j=mid+1;
        
        while(i<=mid && j<=r){
            if(nums[i]>nums[j]){
                temp.push_back(nums[j]);
                j++;
            }
            else{
                temp.push_back(nums[i]);
                i++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=r){
            temp.push_back(nums[j]);
            j++;
        }
        for(int i=l;i<=r;i++){
            nums[i]=temp[i-l];
        }
        
    }
    void mergesort(vector<int>&nums,int l,int r){
        if(l>=r) return;
        int mid=(l+r)/2;
        mergesort(nums,l,mid);
        mergesort(nums,mid+1,r);
        merge(nums,l,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        mergesort(nums,l,r);
        return nums;
    }
};