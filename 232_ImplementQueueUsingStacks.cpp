class MyStack {
    typedef struct StackElement
    {
        int data;
        StackElement *prev;
        StackElement *next;

        StackElement(int x) {
            data = x;
            prev = nullptr;
            next = nullptr;
        };
    } StackElement;
    
private:
    StackElement *top;
    int stackSize;
public:
    MyStack() {
        top = nullptr;
        stackSize = 0;
    }

    void push(int x) {
        if (top == nullptr) {
            top = new StackElement(x);
        } else {
            StackElement *temp = new StackElement(x);
            temp->prev = top;
            top->next = temp;

            top = temp;
        }

        stackSize ++;
    }

    int pop() {
        int ans = top->data;
        if (stackSize == 1) {
            delete top;
            top = nullptr;
        } else {
            StackElement *temp = top;
            top->prev->next = nullptr;
            top = top->prev;
            delete temp;
        }
        stackSize --;

        return ans;
    }

    int peek() {
        return top->data;
    }

    int size() {
        return stackSize;
    }

    int empty() {
        return (stackSize == 0);
    }
};

class MyQueue {
    MyStack s1, s2;
public:
    MyQueue() {
        s1 = MyStack();
        s2 = MyStack();
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int ans;
        while (s1.size() > 1) {
            s2.push(s1.pop());
        }
        ans = s1.pop();
        while (s2.size() > 0) {
            s1.push(s2.pop());
        }
        return ans;
    }
    
    int peek() {
        int ans;
        while (s1.size() > 1) {
            s2.push(s1.pop());
        }
        ans = s1.pop();
        s2.push(ans);
        while (s2.size() > 0) {
            s1.push(s2.pop());
        }
        return ans;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */