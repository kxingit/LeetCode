/*
 * Given an array of integers, every element appears three times except for one. Find that single one.
 */
class Solution {
  public:
    int singleNumber(vector<int>& nums) {
      vector<int> bits(32, 0);
      for(int i = 0; i < nums.size(); i++) {
	for(int j = 0; j < 32; j++) {
	  if((nums[i] >> j) & 1) {
	    bits[j]++;
	  }
	}
      }
      int result = 0;
      for(int j = 0; j < 32; j++) {
	result |= ((bits[j] % 3) << j);
      }
      return result;
    }
};
// v2
class Solution {
  public:
    int singleNumber(vector<int>& nums) {
      vector<int> bits(32, 0);
      for(int i = 0; i < nums.size(); i++) {
	for(int j = 0; j < 32; j++) {
	  if((nums[i] >> j) & 1) bits[j]++;
	}
      }
      int result = 0;
      for(int j = 0; j < 32; j++) {
	result |= ((bits[j] % 3) << j);
      }
      return result;
    }
};
