class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int leftmax=0;
        int rightmax=0;
        int soln=0;
        while(l<r){
            if(height[l]<height[r]){
                leftmax=max(height[l],leftmax);
                soln+=leftmax-height[l];
                l++;
               
            }
            else{
                rightmax=max(height[r],rightmax);
                soln+=rightmax-height[r];
                r--;
                
            }
        }
        return soln;
    }
};
