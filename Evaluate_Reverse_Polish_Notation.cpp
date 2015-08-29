/*
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 */
class Solution {
  public:
    int evalRPN(vector<string>& tokens) {
      stack<int> st;
      for(int i = 0; i < tokens.size(); i++){
	string s = tokens[i];
	char c = s[0];
	if(s.size() == 1 && (c == '+' || c == '-' ||
	      c == '*' || c == '/')){
	  int num = 0;
	  int num2 = st.top();
	  st.pop();
	  int num1 = st.top();
	  st.pop();
	  if(c == '+') num = num1 + num2;
	  if(c == '-') num = num1 - num2;
	  if(c == '*') num = num1 * num2;
	  if(c == '/') num = num2 ? num1 / num2 : 0;
	  st.push(num);
	}
	else{
	  int temp = 0;
	  int j = 0;
	  int sign = 1;
	  if(c == '+' || c == '-'){
	    if(c == '-') sign = -1;
	    j++;
	  }
	  for(; j < s.size(); j++){
	    temp = temp * 10 + s[j] - '0';
	  }
	  st.push(sign * temp);
	}
      }
      return st.top();
    }

};
