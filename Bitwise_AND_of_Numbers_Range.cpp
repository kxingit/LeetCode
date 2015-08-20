/*
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, 
 * return the bitwise AND of all numbers in this range, inclusive.
 */
class Solution {
  public:
    int rangeBitwiseAnd(int m, int n) {
      int mask = INT_MAX;
      // Operator Precedence, "!= is higher
      while((m & mask) != (n & mask)){ 
	mask = mask << 1;
      }
      return m & mask;
    }
};
