/* 
 * Write an efficient algorithm that searches for a value in an m x n matrix. 
 * This matrix has the following properties:
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 */

class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size();
      if(m == 0) return false;
      int n = matrix[0].size();

      // from bottum left
      int mcurr = m - 1, ncurr = 0;
      while(mcurr >= 0 && ncurr < n){
	if(matrix[mcurr][ncurr] == target) return true;
	if(matrix[mcurr][ncurr] < target) ncurr++;
	else mcurr--;
      }
      return false;
    }
};
