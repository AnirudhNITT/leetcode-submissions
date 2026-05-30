class FreqStack {
public:
    unordered_map<int,stack<int>>mp;
    unordered_map<int,int>freq;
    int maxcount;
    FreqStack() {
        maxcount=0;
    }
    
    void push(int val) {
        int freqcount=++freq[val];
        if(maxcount<freqcount){
            stack<int>temp;
            temp.push(val);
            maxcount=freqcount;
            mp[maxcount]=temp;
        }
        else{
            mp[freqcount].push(val);
        }
    }
    
    int pop() {
        int top=mp[maxcount].top();
        freq[top]--;
        mp[maxcount].pop();
        if(mp[maxcount].empty())maxcount--;
        return top;

    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */