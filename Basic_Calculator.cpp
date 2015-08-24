/*
 * tag
 * 1 + (2 + 3)
 * 1> push num and ops to two stacks, untill curr isDigit
 * 2> if curr isDigit, check ops.top(). if '+'/'-', do calculation
 * 3> if curr == ')' && ops.top() == '(', ops.pop()
 */
class Solution {
  public:
    int calculate(string s) {
      int i = 0;
      stack<char> ops;
      stack<int> nums;
      while(i < s.size()){
	if(s[i] == ' '){
	  i++;
	  continue;
	}
	else if(s[i] == ')'){
	  if(ops.top() == '('){
	    ops.pop();
	  }
	  i++; // always ++
	}
	else if(s[i] == '+' || s[i] == '-' || s[i] == '('){
	  ops.push(s[i]);
	  i++;
	  continue;
	}
	else{
	  int num = 0;
	  while(s[i] >= '0' && s[i] <= '9'){ // '0' not 0
	    num = num * 10 + s[i] - '0';
	    i++;
	  }
	  nums.push(num);
	}
	while(!ops.empty() && (ops.top() == '+' || ops.top() == '-')){
	  int num1 = nums.top();
	  nums.pop();
	  int num2 = nums.top();
	  nums.pop();
	  int temp = 0;
	  if(ops.top() == '+'){
	    temp = num2 + num1;
	  }
	  else if(ops.top() == '-'){
	    temp = num2 - num1; // not "num1 - num2"
	  }
	  nums.push(temp);
	  ops.pop();
	}
      }
      return nums.top();
    }
};
