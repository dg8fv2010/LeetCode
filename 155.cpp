class MinStack {
public:
    stack<int> s;
    stack<int> sm;
    void push(int x) {
        s.push(x);
        if (sm.empty()==true || sm.top()>=x)
        {
            sm.push(x);
        }
    }

    void pop() {
        if (s.top()==sm.top())
        {
            sm.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return sm.top();
    }
};