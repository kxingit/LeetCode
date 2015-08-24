/*
 * Number of Digit One
 * 1                   1                                                                                     [1, 9]
 * 
 *  11                 10  11  12  13  14  15  16  17  18  19                              [10, 19]
 * 
 *  1                   21                                                                                   [20, 29]
 * 
 *  1                   31                                                                                   [30, 39]
 * 
 *  1                   41                                                                                   [40, 49]
 * 
 *  1                   51                                                                                   [50, 59]
 * 
 *  1                   61                                                                                   [60, 69]
 * 
 *  1                   71                                                                                   [70, 79]
 * 
 *  1                   81                                                                                   [80, 89]
 * 
 *  1                   91                                                                                   [90, 99]
 */
class Solution {
  public:
    int countDigitOne(int n) {
      // if(n < 0) return -1;
      int res = 0, a = 1, b = 1;
      while (n > 0) {
	res += (n + 8) / 10 * a + (n % 10 == 1) * b;
	b += n % 10 * a;
	a *= 10;
	n /= 10;
      }
      return res;
    }
};
