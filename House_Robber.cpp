/*
 * it will automatically contact the police if two adjacent houses were broken into
 * TIP: if i is broken, either i - 2, or i - 3 must be broken to reach max
 */
class Solution {
  public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      if(!n) return 0;
      vector<int> dp(n, 0);
      dp[0] = nums[0];
      dp[1] = max(nums[0], nums[1]);
      dp[2] = max(nums[0] + nums[2], nums[1]);
      for(int i = 3; i < n; i++){
	dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
      }
      return max(dp[n - 1], dp[n - 2]);
    }
};
