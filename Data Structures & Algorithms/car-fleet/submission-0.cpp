class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>>cars;
        for(int i=0;i<speed.size();i++){
            float rate=(float)(target-position[i])/speed[i];
            cars.push_back({position[i],rate});
        }
         sort(cars.begin(),cars.end());
         double prev=0;
         int fleets=0;
         for(int i=speed.size()-1;i>=0;i--){
            float curr=cars[i].second;
            if(curr>prev){
                prev=curr;
                fleets++;
            }
            }
            return fleets;
       }
       
};
