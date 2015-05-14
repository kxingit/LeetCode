class Solution {
  public:
    int uniquePaths(int m, int n) {
      int nPaths[m][n];
      for(int i = 0; i < m; i++){
	nPaths[i][0] = 1;
      }
      for(int j = 0; j < n; j++){
	nPaths[0][j] = 1;
      }

      for(int i = 1; i < m; i++){
	for(int j = 1; j < n; j++){
	  nPaths[i][j] = nPaths[i - 1][j] + nPaths[i][j - 1];
	}
      }
      return nPaths[m - 1][n - 1];
    }
};
