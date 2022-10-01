class CQueue {
private:
    stack<int> inStack,outStack;
    void inOut()
    {
        while(!inStack.empty())
        {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        inStack.push(value);
    }
    
    int deleteHead() {
        if(outStack.empty())
        {
            if(inStack.empty())
            {
                return -1;
            }
            inOut();
        }
        int value=outStack.top();
        outStack.pop();
        return value;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
