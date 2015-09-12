/*
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 */
class Solution {
  public:
    int numSquares(int n) {
      vector<int> dp(n + 1, INT_MAX);
      dp[0] = 0; // 
      for(int i = 0; i <= n; i++){
	for(int j = 0; i + j * j <= n; j++){
	  dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
	}
      }
      return dp[n];
    }
};
