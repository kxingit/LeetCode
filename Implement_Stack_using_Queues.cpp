/*
 * You must use only standard operations of a queue 
 * -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 */
class Stack {
  public:
    queue<int > q;
    // Push element x onto stack.
    void push(int x) {
      int m = int (q.size());
      q.push(x);
      while (m > 0) {
	int num = q.front();
	q.pop();
	q.push(num);
	m--;
      }
    };

    // Removes the element on top of the stack.
    void pop() {
      q.pop();
    };

    // Get the top element.
    int top() {
      return q.front();
    };

    // Return whether the stack is empty.
    bool empty() {
      return q.empty();
    };
};
