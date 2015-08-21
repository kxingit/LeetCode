/*
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 */
class Solution {
  public:
    int jump(vector<int>& nums) {
      int steps = 0; // min step to get here
      int last = 0; // max position with current step #
      int curr = 0; // curr max range
      for(int i = 0; i < nums.size(); i++){
	if(i > last){
	  steps++;
	  last = curr;
	}
	curr = max(curr, i + nums[i]);
	if(last >= nums.size() - 1) return steps;
      }
      return -1; // no solution
    }
};
