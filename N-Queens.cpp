class Solution {
  private:
    vector<vector<string>> allRes;
  public:
    vector<vector<string> > solveNQueens(int n) {
      vector<int> state(n, -1);
      NQ(state, 0);
      return allRes;
    }
    void NQ(vector<int>& state, int row){
      int n = state.size();
      if(row == n){
	vector<string> res(n, string(n, '.'));
	for(int i = 0; i < n; i++){
	  res[i][state[i]] = 'Q';
	}
	allRes.push_back(res);
	return;
      }
      for(int col = 0; col < n; col++){
	if(isValid(state, row, col)){
	  state[row] = col;
	  NQ(state, row + 1);
	}
      }
    }
    bool isValid(vector<int>& state, int row, int col){
      for(int i = 0; i < row; i++){
	if(col == state[i] || row - i == abs(col - state[i])) // abs!!!
	  return false;
      }
      return true;
    }
};
// v2
class Solution {
  public:
    vector<vector<string>> solveNQueens(int n) {
      vector<int> state(n , -1);
      NQ(state, 0);
      return result;
    }
    void NQ(vector<int> &state, int row) {
      int n = state.size();
      if(row == n) {
	vector<string> solution(n, string(n, '.'));
	for(int i = 0; i < n; i++) {
	  solution[i][state[i]] = 'Q';
	}
	result.push_back(solution);
	return;
      }
      for(int col = 0; col < n; col++) {
	if(isValid(state, row, col)) {
	  state[row] = col;
	  NQ(state, row + 1);
	}
      }
    }
    bool isValid(vector<int> &state, int row, int col) {
      for(int i = 0; i < row; i++) {
	if(col == state[i] || row - i == abs(col - state[i])) {
	  return false;
	}
      }
      return true;
    }
  private: 
    vector<vector<string>> result;
};
// v3
class Solution {
  public:
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> result;
      vector<int> state(n, -1);
      NQ(0, state, result);
      return result;
    }
    void NQ(int row, vector<int> &state, vector<vector<string>> &result) {
      int n = state.size();
      if(row == n) {
	vector<string> solution(n, string(n, '.'));
	for(int i = 0; i < n; i++) {
	  solution[i][state[i]] = 'Q';
	}
	result.push_back(solution);
	return;
      }
      for(int col = 0; col < n; col++) {
	if(isValid(state, row, col)) {
	  state[row] = col;
	  NQ(row + 1, state, result);
	}
      }
    }
    bool isValid(vector<int> &state, int row, int col) {
      for(int i = 0; i < row; i++) {
	if(col == state[i] || row - i == abs(col - state[i])) {
	  return false;
	}
      }
      return true;
    }
};
// v4
class Solution {
  public:
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> result;
      vector<int> solution(n, -1);
      NQ(0, solution, result);
      return result;
    }
    void NQ(int row, vector<int> &solution, vector<vector<string>> &result) {
      int n = solution.size();
      if(row == n) {
	vector<string> res(n, string(n, '.'));
	for(int i = 0; i < n; i++) {
	  res[i][solution[i]] = 'Q';
	}
	result.push_back(res);
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
