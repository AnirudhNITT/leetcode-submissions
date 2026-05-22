class MinStack {
public:
    stack<int>st1;
    stack<int>st2;
    int top1=-1;
    int top2=-1;
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        top1++;
        if(top2==-1 || st2.top()>=val){
            st2.push(val);
            top2++;
        }
    }
    
    void pop() {
        if(top1==-1)return;
        int val=st1.top();
        st1.pop();
        top1--;
        if(val==st2.top()){
        st2.pop();
        top2--;
        }
    }
    
    int top() {
        if(top1==-1)return -1;
        return st1.top();
    }
    
    int getMin() {
        if(top2==-1)return 0;
        return st2.top();
    }
};
