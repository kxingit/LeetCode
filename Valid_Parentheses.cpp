/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 */
class Solution {
  public:
    bool isValid(string s) {
      vector<char> stack;
      for(int i = 0; i < s.size(); i++){
	if(s[i] == '(' or s[i] == '[' or s[i] == '{'){
	  stack.push_back(s[i]);
	  continue;
	}
	else if(stack.size() == 0) return false;

	if(s[i] == ')' && stack.back() != '(') return false;
	if(s[i] == ']' && stack.back() != '[') return false;
	if(s[i] == '}' && stack.back() != '{') return false;
	stack.pop_back();
      }
      if(stack.size() != 0) return false;
      else return true;
    }
};
// v2
class Solution {
  public:
    bool isValid(string s) {
      stack<char> st;
      for(auto i : s) {
	if(i == '(' || i == '{' || i == '[') {
	  st.push(i);
	  continue;
	}
	if(st.empty()) return false;
	auto temp = st.top();
	st.pop();
	if(i == ')' && temp != '(') return false;
	if(i == ']' && temp != '[') return false;
	if(i == ']' && temp != '[') return false;
      }
      if(st.empty()) return true;
    }
};
