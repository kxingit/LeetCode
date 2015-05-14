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
