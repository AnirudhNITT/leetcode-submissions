/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>start;
        vector<int>end;
        for(auto interval :intervals){
            start.push_back(interval.start);
            end.push_back(interval.end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int s=0;
        int e=0;
        int count=0;
        int best_count=0;
        while(s<start.size()){
            if(start[s]<end[e]){
                count++;
                s++;
            }
            else {
                count--;
                e++;
            }
            best_count=max(count,best_count);
        }
        return best_count;
    }
};
