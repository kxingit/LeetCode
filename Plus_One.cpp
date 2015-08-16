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
/* a faster solution
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
*/
