class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
    }
    
    void push(int x) {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++) {
            int ele = q.front();
            q.pop();
            q.push(ele);
        }
    }
    
    int pop() {
        int ele = q.front();  // fix here
        q.pop();
        return ele;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */