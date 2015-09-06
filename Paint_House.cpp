/*
 * There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. 
 * The cost of painting each house with a certain color is different. 
 *You have to paint all the houses such that no two adjacent houses have the same color.
 */
class Solution {
  public:
    int minCost(vector<vector<int>>& costs) {
      int m = costs.size();
      if(!m) return 0;
      vector<vector<int>> dp(m, vector<int>(3, 0));
      for(int i = 0; i < m; i++){
	for(int j = 0; j < 3; j++) {
	  if(i == 0) { 
	    dp[i][j] = costs[i][j];
	    continue;
	  }
	  int temp = INT_MAX;
	  for(int k = 0; k < 3; k++){
	    if(k != j) temp = min(temp, dp[i - 1][k]);
	  }
	  dp[i][j] = temp + costs[i][j];
	}
      }
      return min(dp[m - 1][0], min(dp[m - 1][1], dp[m - 1][2]));
    }
};
