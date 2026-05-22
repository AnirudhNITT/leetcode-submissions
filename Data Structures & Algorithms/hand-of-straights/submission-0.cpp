class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int>ms;
        for(int i=0;i<hand.size();i++){
            ms.insert(hand[i]);
        }
        if(hand.size()%groupSize!=0)return false;
        while(!ms.empty()){
            int val=*ms.begin();
            for(int i=0;i<groupSize;i++){
                if(ms.find(val)==ms.end())return false;
                else{
                    ms.erase(ms.find(val));
                }
                val++;
            }
        }
        return true;
    }
};
