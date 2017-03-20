/*
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 */
// Time Limit Exceeded
class MinStack {
  public:
    int mini = INT_MAX;
    stack<int> st;
    vector<int> v;
    void push(int x) {
      if(st.empty()) mini = x;
      else mini = min(mini, st.top());
      st.push(x);
      v.push_back(x);
      sort(v.begin(), v.end());
    }

    void pop() {
      auto it = find(v.begin(), v.end(), st.top());
      v.erase(it);
      if(v.size()) mini = v[0];
      st.pop();
    }

    int top() {
      return st.top();
    }

    int getMin() {
      return mini;
    }
};

// better
class MinStack {
  public:
    int mini = INT_MAX;
    stack<int> st;
    stack<int> stmin;
    void push(int x) {
      st.push(x);
      if(stmin.empty()) stmin.push(x);
      else stmin.push(min(stmin.top(), x));
    }

    void pop() {
      stmin.pop();
      st.pop();
    }

    int top() {
      return st.top();
    }

    int getMin() {
      return stmin.top();
    }
};

// v3
class MinStack {
public:
    /** initialize your data structure here. */
    // 7:59 - 8:09
    stack<int> st;
    stack<int> minst;
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(minst.empty()) {
            minst.push(x);
        } else {
            minst.push(min(x, minst.top()));
        }
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};


// v4
class MinStack {
public:
    /** initialize your data structure here. */
    // 7:59 - 8:09 - 8:12
    stack<int> st;
    stack<int> minst;
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(minst.empty()) {
            minst.push(x);
        } else {
            if(x <= minst.top()) {
                minst.push(min(x, minst.top()));
            }
        }
    }
    
    void pop() {
        if(st.top() == minst.top()) {
            minst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
