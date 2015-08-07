/* 
 * Reverse bits of a given 32 bits unsigned integer.
 */
class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
      int result = 0;
      for(int i = 0; i < 32; i++){ // loop all bits. while: X
	int last = n & 1;
	n = n >> 1;
	result = result << 1 | last; // "+ last": X
      }
      return result;
    }
};
