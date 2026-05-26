class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int,vector<int>,greater<int>>min;
    priority_queue<int>max;
    int count=0;
    void addNum(int num) {
        if(max.size()==0){
            max.push(num);
            return;
        }
        int max_num=max.top();
        if(num<=max_num) max.push(num);
        else min.push(num);
        while((min.size()>max.size()+1)){
            int top=min.top();
            min.pop();
            max.push(top);
        }
        while((max.size()>min.size()+1)){
            int top=max.top();
            max.pop();
            min.push(top);
        }
    }
    
    double findMedian() {
         int s=min.size()+max.size();
        if(s%2==1){
            if(max.size()>min.size()) return max.top();
            return min.top();
        }
        return (min.top()+max.top())/2.0;
    }
};
