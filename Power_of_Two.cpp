/*
 * Given an integer, write a function to determine if it is a power of two.
 */
class Solution {
  public:
    bool isPowerOfTwo(int n) {
      if(n <= 0) return false;
      return !(n & n - 1);
    }
};

class Solution {
  public:
    bool isPowerOfTwo(int n) {
      if(n == 1) return true;
      if(n == 0) return false;
      while(n){
	if(n % 2 != 0) return false;
	n = n / 2;
	if(n == 1) return true;
      }
      return true;
    }
};
