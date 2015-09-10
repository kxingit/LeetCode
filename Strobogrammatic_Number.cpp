/*
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 */
class Solution {
  public:
    bool isStrobogrammatic(string num) {
      int n = num.size();
      if(!n) return true;
      int i = 0, j = n - 1;
      while(i < j){
	if(!isSpair(num, i, j)) return false;
	i++;
	j--;
      }
      if(i == j){
	if(isSnum(num[i])) return true;
	else return false;
      }
      else{
	return true;
      }
    }

    bool isSpair(string& num, int i, int j){
      if(num[i] == '0' && num[j] == '0'
	  || num[i] == '1' && num[j] == '1'
	  || num[i] == '8' && num[j] == '8'
	  || num[i] == '6' && num[j] == '9'
	  || num[i] == '9' && num[j] == '6')
	return true;
      else return false;
    }
    bool isSnum(char& c){
      if(c == '0' || c == '1' || c == '8') return true;
      else return false;
    }
};
// v2
class Solution {
  public:
    bool isStrobogrammatic(string num) {
      int n = num.size();
      if(!n) return true;
      int i = 0, j = n - 1;
      while(i <= j){ // making a pair itself
	if(!isSpair(num, i, j)) return false;
	i++;
	j--;
      }
      return true;
    }

    bool isSpair(string& num, int i, int j){
      if(num[i] == '0' && num[j] == '0'
	  || num[i] == '1' && num[j] == '1'
	  || num[i] == '8' && num[j] == '8'
	  || num[i] == '6' && num[j] == '9'
	  || num[i] == '9' && num[j] == '6')
	return true;
      else return false;
    }
};
// v3
class Solution {
  public:
    bool isStrobogrammatic(string num) {
      int n = num.size();
      if(!n) return true;
      int i = 0, j = n - 1;
      while(i <= j) {
	if(!isStrobo(num[i], num[j])) return false;
	i++;
	j--;
      }
      return true;
    }
    bool isStrobo(char a, char b){
      bool temp = (a == '0' && b == '0') || (a == '1' && b == '1')
	|| (a == '6' && b == '9') || (a == '8' && b == '8')
	|| (a == '9' && b == '6');
      if(temp) return true;
      else return false;
    }
};
