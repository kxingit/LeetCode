/*
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 */
class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
      int i = 0, j = 0;
      while(i < nums.size()) { 
	if(nums[i] == 0) {
	  i++;
	  continue;
	}
	else {
	  nums[j] = nums[i];
	  i++;
	  j++;
	}
      }
      while(j < nums.size()) {
	nums[j] = 0;
	j++;
      }
    }
};
