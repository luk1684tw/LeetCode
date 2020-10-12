#include <stack>
#include <limits>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        s1.push(x);

        if (s2.empty() || x <= s2.top()) s2.push(x);
        return;
    }
    
    void pop() {
        if (s1.top() == s2.top()) s2.pop();

        s1.pop();
        return;
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }

private:
    stack<int> s1;
    stack<int> s2;

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */