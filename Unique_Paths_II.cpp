/*
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 */
class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      if(m == 0) return 0;
      int nPath[m][n];
      // boundary 
      nPath[0][0] = obstacleGrid[0][0] ? 0 : 1;
      if(nPath[0][0] == 0) return 0;
      for(int j = 1; j < n; j++)
	nPath[0][j] = obstacleGrid[0][j] == 0 ? nPath[0][j - 1] : 0;
      // dp
      for(int i = 1; i < m; i++){
	nPath[i][0] = obstacleGrid[i][0] ? 0 : nPath[i - 1][0];
	for(int j = 1; j < n; j++){
	  nPath[i][j] = obstacleGrid[i][j] ? 0 : nPath[i - 1][j] + nPath[i][j - 1];
	}
      }
      return nPath[m - 1][n - 1];
    }
};
