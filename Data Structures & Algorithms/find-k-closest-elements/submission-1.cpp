class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pivot;
        priority_queue<int,vector<int>,greater<int>>pq;
        int min_val=abs(x-arr[0]);
        for( int i=0;i<arr.size();i++){
            min_val=min(min_val,abs(x-arr[i]));
            if(min_val==abs(x-arr[i]))pivot=i;
        }
        pq.push(arr[pivot]);
        k--;
        int l=pivot-1;
        int r=pivot+1;
        while(k>0){
            while(l>=0 &&r<arr.size()){
                int left_diff=abs(x-arr[l]);
                int right_diff=abs(x-arr[r]);
                if(left_diff>right_diff){
                    if(k==0)break;
                    pq.push(arr[r]);
                    r++;
                    k--;
                    
                }
                else{
                    if(k==0)break;
                    pq.push(arr[l]);
                    l--;
                    k--;
                }
            }
            while(l>=0){
                if(k==0)break;
                pq.push(arr[l]);
                l--;
                k--;
            }
            while(r<arr.size()){
                if(k==0)break;
                pq.push(arr[r]);
                r++;
                k--;
            }
        }
        vector<int>soln;
        while(!pq.empty()){
            soln.push_back(pq.top());
            pq.pop();
            
        }
        return soln;
    }
};