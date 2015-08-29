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
