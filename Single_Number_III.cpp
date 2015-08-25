/*
 * Given an array of numbers nums, in which exactly two elements appear only once
 * and all the other elements appear exactly twice. Find the two elements that appear only once.
 */
class Solution {
  public:
    vector<int> singleNumber(vector<int>& nums) {
      int full = 0;
      int n = nums.size();
      vector<int> result;
      for(int i = 0; i < n; i++){
	full ^= nums[i];
      }
      int mask = 1; // mask for the different digit
      for(int i = 0; i < n; i++){
	int digit = full & 1;
	full = full >> 0x01;
	if(digit == 1) break;
	mask = mask << 1;
      }
      int num1 = 0, num2 = 0;
      for(int i = 0; i < n; i++){
	if(nums[i] & mask){
	  num1 ^= nums[i];
	}
	else{
	  num2 ^= nums[i];
	}
      }
      result.push_back(num1);
      result.push_back(num2);
      return result;
    }
};
