/*
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
 * You may assume all four edges of the grid are all surrounded by water.
 */
class Solution {
  public:
    int numIslands(vector<vector<char>>& grid) {
      int m = grid.size();
      if(m == 0) return 0;
      int n = grid[0].size();
      int nIslands = 0;
      for(int i = 0; i < m; i++){
	for(int j = 0; j < n; j++){
	  if(grid[i][j] == '1'){
	    dfs(grid, i ,j);
	    nIslands++;
	  }
	}
      }
      return nIslands;
    }
    void dfs(vector<vector<char>>& grid, int i, int j){
      int m = grid.size();
      int n = grid[0].size();
      if(i < 0 || i >= m || j < 0 || j >= n) return;
      if(grid[i][j] != '1') return;
      grid[i][j] = '*';
      dfs(grid, i + 1, j);
      dfs(grid, i, j + 1);
      dfs(grid, i - 1, j);
      dfs(grid, i, j - 1);
    }
};
// v2
class Solution {
  public:
    int numIslands(vector<vector<char>>& grid) {
      int m = grid.size();
      if(!m) return 0;
      int n = grid[0].size();
      int count = 0;
      for(int i = 0; i < m; i++) {
	for(int j = 0; j < n; j++) {
	  if(grid[i][j] == '1') {
	    expend(grid, i, j);
	    count++;
	  }
	}
      }
      return count;
    }
    void expend(vector<vector<char>>& grid, int i, int j) {
      if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
      if(grid[i][j] != '1') return;
      if(grid[i][j] == '1') grid[i][j] = '*';
      expend(grid, i - 1, j);
      expend(grid, i + 1, j);
      expend(grid, i, j - 1);
      expend(grid, i, j + 1);
    }
};
