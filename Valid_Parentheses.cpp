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
