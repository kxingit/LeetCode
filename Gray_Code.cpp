/* 
 * Gray Code
 */

class Solution {
  public:
    vector<int> grayCode(int n) {
      vector<int> result;
      int size = 1 << n;  // number of output is 2^n_digits
      for(int i = 0; i < size; i++){
	result.push_back((i >> 1) ^ i); // wiki method
      }
      return result;  
    }
};
