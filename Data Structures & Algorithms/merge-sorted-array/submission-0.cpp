class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int back=m+n-1;
        int curr_1=m-1;
        int curr_2=n-1;
        while(back>=0 && curr_1>=0 && curr_2>=0){
            if(nums1[curr_1]>=nums2[curr_2]){
                nums1[back]=nums1[curr_1];
                curr_1--;
            }
            else{
                nums1[back]=nums2[curr_2];
                curr_2--;
            }
            back--;
        }
        while(curr_2>=0){
            nums1[back]=nums2[curr_2];
            back--;
            curr_2--;
        }
    }
};