class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        multiset<int> ms;

        for (int x : nums) {
            ms.insert(x);
            if (ms.count(x) > 1) {
                return true;   
            }
        }
        return false;   
    }
};
