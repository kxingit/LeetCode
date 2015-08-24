/*
 * Given a 2D binary matrix filled with 0's and 1's, find the largest 
 * square containing all 1's and return its area.
 */
class Solution {
  public:
    int maximalSquare(vector<vector<char>>& matrix) {
      int m = matrix.size(); 
      if(!m) return 0; // before n
      int n = matrix[0].size();
      vector<vector<int>> dp(m, vector<int>(n, 0));
      int result = 0;
      for(int i = 0; i < m; i++){
	dp[i][0] = matrix[i][0] - '0';
	result = max(result, dp[i][0]);
      }
      for(int j = 0; j < n; j++){
	dp[0][j] = matrix[0][j] - '0';
	result = max(result, dp[0][j]);
      }
      for(int i = 1; i < m; i++){ // starts from 1
	for(int j = 1; j < n; j++){
	  if(matrix[i][j] - '0'){
	    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
	  }
	  else{
	    dp[i][j] = 0;
	  }
	  result = max(result, dp[i][j]);
	}
      }
      return result * result;
    }
};
