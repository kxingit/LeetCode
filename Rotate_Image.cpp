/*
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 */

class Solution {
  public:
    void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();
      // flip wrt diagonal line "\"
      for(int i = 0; i < n - 1; i++){
	for(int j = 0; j < n - i; j++){
	  swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
	}
      }
      // flip wrt vertical middle line
      for(int i = 0; i < n / 2; i++){ // "<="
	for(int j = 0; j < n; j++){
	  swap(matrix[i][j], matrix[n - 1 - i][j]);
	}
      }
    }
    void swap(int& a, int& b){
      int temp = a;
      a = b;
      b = temp;
    }
};
