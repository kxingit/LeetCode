/* 
 * Given an array of n positive integers and a positive integer s, 
 * find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 */
class Solution {
  public:
    int minSubArrayLen(int s, vector<int>& nums) {
      if (nums.empty()) return 0;
      int left = 0, right = -1, sum = 0, len = nums.size(), res = len + 1;
      while (right < len) {
	while (sum < s && right < len) sum += nums[++right];
	if (sum >= s) {
	  res = min(res, right - left + 1);
	  sum -= nums[left++];
	}
      }
      return res == len + 1 ? 0 : res;
    }
};
