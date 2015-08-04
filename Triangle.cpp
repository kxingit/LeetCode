/* 
 * Given a triangle, find the minimum path sum from top to bottom. 
 * Each step you may move to adjacent numbers on the row below.
 */
class Solution {
  public:
    int minimumTotal(vector<vector<int>>& triangle) {
      int row = triangle.size();
      // if(row == 0) return 0;
      int result[triangle[row - 1].size()];
      for(int i = row - 1; i >= 0; i--){
	int col = triangle[i].size();
	for(int j = 0; j < col; j++){
	  if(i == row - 1) result[j] = triangle[i][j];
	  else result[j] = min(result[j], result[j + 1]) + triangle[i][j];
	}
      }
      return result[0];
    }
};
