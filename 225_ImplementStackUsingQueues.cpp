class MyQueue {
    typedef struct QueueElement
    {
        int             data;
        QueueElement   *prev;
        QueueElement   *next;

        QueueElement(int x) {
            data = x;
            prev = nullptr;
            next = nullptr;
        }
    } QueueElement;

private:
    QueueElement *head;
    QueueElement *tail;
    int queueSize;
public:

    MyQueue() {
        head = nullptr;
        tail = nullptr;
        queueSize = 0;
    }

    void push(int x) {
        if (head == nullptr) {
            head = new QueueElement(x);
            tail = head;
        } else {
            QueueElement *temp = new QueueElement(x);
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        queueSize++;
    }

    int pop() {
        int ans = head->data;
        if (queueSize == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            QueueElement *temp = head;
            head->next->prev = nullptr;
            head = head->next;
            delete temp;
        }
        queueSize--;
        return ans;
    }

    int top() {
        return head->data;
    }

    bool empty() {
        return (queueSize == 0);
    }

    int size() {
        return queueSize;
    }

};

class MyStack {
private:
    MyQueue q1;
    MyQueue q2;
public:
    MyStack() {
        q1 = MyQueue();
        q2 = MyQueue();
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int ans = 0;
        while (q1.size() > 1) {
            q2.push(q1.pop());
        }
        ans = q1.pop();
        while (q2.size() > 0) {
            q1.push(q2.pop());
        }
        return ans;
    }
    
    int top() {
        int ans = 0;
        while (q1.size() > 1) {
            q2.push(q1.pop());
        }
        ans = q1.top();
        q2.push(q1.pop());
        while (q2.size() > 0) {
            q1.push(q2.pop());
        }
        return ans;
    }
    
    bool empty() {
        return q1.empty();
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
