class Solution {
  public:
    int reverse(int x) {
      bool isNeg = 0; // 1: neg; 0: pos
      if(x < 0) {
	isNeg = 1;
	x = -1 * x;
      }
      long result = 0;
      while(x > 0){
	result = result * 10 + x % 10;
	x = x /10;
      }
      if(result > INT_MAX) return 0;
      if(isNeg) 
	return result * (-1);
      else
	return result;
    }
};
