/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &nums) {
        int l=0,r=nums.length()-1;

        while(l<r){
            int mid=(l+r)/2;
            if(nums.get(mid)<nums.get(mid+1))
                l=mid+1;
            else
                r=mid;
        }

        int peak=l;

        l=0;
        r=peak;

        while(l<=r){
            int mid=(l+r)/2;
            int x=nums.get(mid);

            if(x==target) return mid;
            else if(x<target) l=mid+1;
            else r=mid-1;
        }

        l=peak+1;
        r=nums.length()-1;

        while(l<=r){
            int mid=(l+r)/2;
            int x=nums.get(mid);

            if(x==target) return mid;
            else if(x<target) r=mid-1;
            else l=mid+1;
        }

        return -1;
    }
};