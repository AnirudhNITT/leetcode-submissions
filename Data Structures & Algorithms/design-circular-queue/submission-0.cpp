class DLL{
public:
    int val;
    DLL* prev;
    DLL* next;
    DLL(int v){
        val=v;
        prev=NULL;
        next=NULL;
    }
};
class MyCircularQueue {
public:
    int curr_capacity;
    int max_capacity;
    DLL* head;
    DLL* tail;
    MyCircularQueue(int k) {
        curr_capacity=0;
        max_capacity=k;
        head=NULL;
        tail=NULL;    
    }
    
    bool enQueue(int value) {
        if(isFull())return false;
        else if(curr_capacity==0){
            DLL* new_node=new DLL(value);
            head=new_node;
            tail=new_node;
            head->next=head;
            head->prev=head;
        }
        else{
           DLL* new_node=new DLL(value);
            new_node->prev=tail;
            new_node->next=head;
            tail->next=new_node;
            head->prev=new_node;
            tail=new_node;
        }
        curr_capacity++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        else if(curr_capacity==1){
            head=NULL;
            tail=NULL;
        }
        else{
            DLL* new_head=head->next;
            tail->next=new_head;
            new_head->prev=tail;
            head->next=NULL;
            head->prev=NULL;
            head=new_head;
        }
        curr_capacity--;
        return true;
    }
    
    int Front() {
        if(!isEmpty())return head->val;
        return -1;
    }
    
    int Rear() {
        if(!isEmpty())return tail->val;
        return -1;
    }
    
    bool isEmpty() {
        if(curr_capacity==0)return true;
        return false;
    }
    
    bool isFull() {
        if(curr_capacity==max_capacity)return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */