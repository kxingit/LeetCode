/*
 * tag
 * There is a fence with n posts, each post can be painted with one of the k colors.
 * You have to paint all the posts such that no more than two adjacent fence posts have the same color.
 * Return the total number of ways you can paint the fence.
 */
// Time Limit Exceeded
class Solution {
  public:
    int numWays(int n, int k) {
      if(!n || !k) return 0;
      vector<vector<int>> dp(n, vector<int>(k, 0));
      for(int i = 0; i < n; i++){
	for(int j = 0; j < k; j++){
	  if(i == 0) dp[0][j] = k;
	  else dp[i][j] = nNoJ(dp, i, j, k);
	}
      }
      int result = 0;
      for(int i = 0; i < k; i++){
	result += dp[n - 1][i];
      }
      return result;
    }
    int nNoJ(vector<vector<int>> &dp, int i, int j, int k){
      int result = 0;
      for(int l = 0; l < k; l++){
	if(l != j){
	  result += dp[i - 1][l];
	}
      }
      return result;
    }
};
// v2
/*
 * I use s (same) to stand for the number of ways when the last two fences are painted with the same color (the last element of dp1 in the above post) and d (different) with d1 and d2 to stand for the last two elements of dp2 in the above post.

 In each loop, dp1[i] = dp2[i - 1] turns into s = d2 and dp2[i] = (k - 1) * (dp2[i - 2] + dp2[i - 1]) becomes d2 = (k - 1) * (d1 + d2). Moreover, d1 needs to be set to the oldd2, which is recorded in s. So we have d1 = s.
 */

class Solution {
  public:
    int numWays(int n, int k) {
      if (n < 2 || !k) return n * k; 
      int s = k, d1 = k, d2 = k * (k - 1); 
      for (int i = 2; i < n; i++) {
	s = d2;
	d2 = (k - 1) * (d1 + d2);
	d1 = s;
      }
      return s + d2;
    }
};
// v3: better variable names
class Solution {
  public:
    int numWays(int n, int k) {
      if(n == 0) return 0;
      if(n <= 2) return pow(k, n);
      int same = k;
      int notSame = k * (k - 1);
      for(int i = 3; i <= n; i++) {
	int temp = same;
	same = notSame;
	notSame = (k - 1) * temp + (k - 1) * notSame;
      }
      return same + notSame;
    }
};
