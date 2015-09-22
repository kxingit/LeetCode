/*
 * Given a 2D board and a word, find if the word exists in the grid.
 */
class Solution {
  public:
    bool exist(vector<vector<char>>& board, string word) {
      int m = board.size();
      if(!m) return false;
      int n = board[0].size();
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      for(int i = 0; i < m; i++) {
	for(int j = 0; j < n; j++) {
	  if(findWord(board, visited, i, j, word, 0)) return true;
	}
      }
      return false;
    }
    bool findWord(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col, string word, int index) {
      if(index == word.size()) return true;
      if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() 
	  || visited[row][col] || board[row][col] != word[index]) 
	return false;
      visited[row][col] = true;
      if(findWord(board, visited, row + 1, col, word, index + 1)) return true;
      if(findWord(board, visited, row - 1, col, word, index + 1)) return true;
      if(findWord(board, visited, row, col + 1, word, index + 1)) return true;
      if(findWord(board, visited, row, col - 1, word, index + 1)) return true;
      visited[row][col] = false;
      return false;
    }
};
// v2
class Solution {
  public:
    bool exist(vector<vector<char>>& board, string word) {
      int m = board.size();
      if(!m) return false;
      int n = board[0].size();
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      for(int i = 0; i < m; i++) {
	for(int j = 0; j < n; j++) {
	  if(findWord(board, visited, i, j, word, 0)) return true;
	}
      }
      return false;
    }
    bool findWord(vector<vector<char>>& board, vector<vector<bool>> &visited, int row, int col, string &word, int index) {
      if(index == word.size()) return true;
      if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() 
	  || board[row][col] != word[index] || visited[row][col]) 
	return false;
      visited[row][col] = true;
      if(findWord(board, visited, row + 1, col, word, index + 1)) return true;
      if(findWord(board, visited, row - 1, col, word, index + 1)) return true;
      if(findWord(board, visited, row, col + 1, word, index + 1)) return true;
      if(findWord(board, visited, row, col - 1, word, index + 1)) return true;
      visited[row][col] = false;
      return false;
    }
};
