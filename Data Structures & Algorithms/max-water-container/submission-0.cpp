class Solution {
public:

    int maxArea(vector<int>& heights) {
        int max_area=0;
        int length=heights.size()-1;
        auto start= heights.begin();
        auto end= heights.end()-1;
        while(start<end){
                int min=((*start)<(*end))?(*start):(*end);
                if (max_area<(min*length)){
                    max_area= min*length;
                }
                if(min==*start){
                    start++;
                    length--;
                }
                else{
                    end--;
                    length--;
                }
        }
        return max_area;
        
    }
};
