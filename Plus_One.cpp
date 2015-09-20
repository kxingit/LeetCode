/*
 * Given a non-negative number represented as an array of digits, plus one to the number.
 */
class Solution {
  public:
    vector<int> plusOne(vector<int>& digits) {
      int cary = 1, sum = 0;  
      vector<int> result(digits.size(),0);  
      for(int i = digits.size() - 1; i >= 0; i--)  
      {        
	sum = cary + digits[i];  
	cary = sum / 10;  
	result[i] = sum % 10;  
      }  
      if(cary > 0)  
      {  
	result.insert(result.begin(), cary);  
      }  
      return result;
    }
};
// v2
class Solution {
  public:
    vector<int> plusOne(vector<int>& digits) {
      vector<int> result = digits;
      int n = result.size();
      if(n == 0){
	result.push_back(1);
	return result;
      }
      for(int i =  n - 1; i >= 0; i--){ // [0] is the highest!!!
	if(result[i] < 9){
	  result[i] = result[i] + 1;
	  return result;
	}
	else{
	  result[i] = 0;
	}
      }
      if(result[0] == 0)  result.insert(result.begin(), 1);
      return result;

    }
};
// v3
class Solution {
  public:
    vector<int> plusOne(vector<int>& digits) {
      int n = digits.size();
      int curr, carry;
      for(int i = digits.size() - 1; i >= 0; i--) {
	if(i == digits.size() - 1) {
	  curr = digits[i] + 1;
	}
	else { 
	  curr = digits[i] + carry;
	}
	carry = curr / 10;
	digits[i] = curr % 10;
      }
      if(carry > 0) {
	digits.insert(digits.begin(), 1);
      }
      return digits;
    }
};
// v4
class Solution {
  public:
    vector<int> plusOne(vector<int>& digits) {
      int i = digits.size() - 1;
      int carry = 0;
      while(i >= 0) {
	int curr;
	if(i == digits.size() - 1) curr = digits[i] + 1;
	else curr = digits[i] + carry;
	digits[i] = curr % 10;
	carry = curr / 10;
	i--;
      }
      if(carry) {
	digits.insert(digits.begin(), carry);
      }
      return digits;
    }
};
