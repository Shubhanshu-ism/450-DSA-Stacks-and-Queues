// Stack class.
class Stack {
    int *st;
    int tp;
    int max=0;
public:
    
    Stack(int capacity) {
        this->max=capacity;
        st = new int[max];
        tp=-1;
    }

    void push(int num) {
        if(!isFull()){
            st[++tp]=num;
        }
        else return;
       
    }

    int pop() {
        if(!isEmpty()){
            int a = st[tp--];  //important
            return a;
        }
        else return -1;
        
    }
    
    int top() {
        if(tp==-1) return -1;
        return st[tp];
    }
    
    int isEmpty() {
        return tp==-1;
    }
    
    int isFull() {
        return tp==max-1;
    }
    
};
