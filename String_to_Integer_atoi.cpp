/*
 * Implement atoi to convert a string to an integer.
 */
class Solution {
  public:
    int myAtoi(string str) {
      long result = 0;
      bool hasNum = 0;
      bool hasSign = 0;
      int sign = 1;
      for(int i = 0; i < str.size(); i++){
	if(str[i] == ' '){ 
	  if(hasNum || hasSign) return regulateResult(result, sign);
	  else continue;
	}
	if(str[i] == '+'){
	  if(hasNum || hasSign) return 0;
	  sign = 1;
	  hasSign = 1;
	  continue;
	}
	if(str[i] == '-'){ 
	  if(hasNum || hasSign) return 0;
	  sign = -1;
	  hasSign = 1;
	  continue;
	}
	if(char2num(str[i]) >= 0 && char2num(str[i]) <= 9){
	  hasNum = 1;
	  result = result * 10 + str[i] - '0';
	  if(result * sign > INT_MAX) return INT_MAX;
	  if(result * sign < INT_MIN) return INT_MIN;
	}
	if(char2num(str[i]) < 0 || char2num(str[i]) > 9){
	  if(hasNum == 0) return 0;
	  else{
	    return regulateResult(result, sign);
	  }
	}
      }
      return regulateResult(result, sign);
    }
    int char2num(char c){
      return c - '0';
    }
    int regulateResult(long result, int sign){
      result = result * sign;
      if(result < INT_MIN) return INT_MIN;
      if(result > INT_MAX) return INT_MAX;
      return result;
    }
};

// better
class Solution {
  public:
    int myAtoi(string str) {
      int i = 0;
      int sign = 1;
      int res = 0;
      while (str[i]==' ') i++;
      if (str[i]=='+'){ 
	i++;
      }
      else if (str[i]=='-'){ 
	sign = -1;
	i++;
      }
      if (!isdigit(str[i])) return 0;
      while (isdigit(str[i])){
	if (sign * res > INT_MAX / 10) return INT_MAX;
	if (sign * res == INT_MAX / 10 && int(str[i] - '0') >= 7) return INT_MAX;
	if (sign * res < INT_MIN / 10) return INT_MIN;
	if (sign * res == INT_MIN / 10 && int(str[i] - '0') >= 8) return INT_MIN;
	res = res * 10 + int(str[i] - '0');
	i++;
      }

      return sign * res;
    }
};
