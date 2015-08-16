/*
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 * O(1): Digital root: return num - 9 * ((num - 1) / 9);
 */
class Solution {
  public:
    int addDigits(int num) {
      int sum = num;
      while(sum > 9){
	num = sum;
	sum = 0;
	while(num){
	  int digit = num % 10;
	  num = num / 10;
	  sum += digit;
	}
      }
      return sum;
    }
};
