/*
 * Given an integer n, return the number of trailing zeroes in n!.
 * TIP: # of "5" is simply n / 5; duplacates are in n / 5 / 5, so do another divided by 5 * 5
 */ 

class Solution {
  public:
    int trailingZeroes(int n) {
      int result = 0;
      while(n >= 5){
	result += n / 5;
	n = n / 5;
      }
      return result;
    }
};
