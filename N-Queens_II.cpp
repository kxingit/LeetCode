/*
 * outputting board configurations, return the total number of distinct solutions.
 */
class Solution {
  public:
    int totalNQueens(int n) {
      int result = 0;
      vector<int> solution(n, -1);
      NQ(0, solution, result);
      return result;
    }
    void NQ(int row, vector<int> &solution, int &result) {
      int n = solution.size();
      if(row == n) {
	result++;
      }
      for(int i = 0; i < n; i++) {
	if(isValid(row, i, solution)) {
	  solution[row] = i;
	  NQ(row + 1, solution, result);
	}
      }
    }
    bool isValid(int row, int col, vector<int> &solution) {
      for(int i = 0; i < row; i++) {
	if(col == solution[i] || row - i == abs(col - solution[i])){
	  return false;
	}
      }
      return true;
    }
};
