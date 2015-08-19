/*
 * This time, all houses at this place are arranged in a circle.
 */
class Solution {
  public:
    int rob(vector<int>& nums) {
      if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
      // max can be obtained by either removing nums[0] or nums[n - 1]
      return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
    }
    int rob(vector<int> &nums, int start, int end) {
      int a = 0, b = 0;
      for (int i = start; i < end; ++i) {
	int m = a, n = b;
	a = n + nums[i];
	b = max(m, n);
      }
      return max(a, b);
    }
};
