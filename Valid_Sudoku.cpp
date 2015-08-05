/* 
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 * A valid Sudoku board (partially filled) is not necessarily solvable. 
 * Only the filled cells need to be validated.
 */
class Solution {
  public:
    bool isValidSudoku(vector<vector<char>>& board) {
      int isUsed[9];
      // check row
      for(int i = 0; i < 9; i++){
	memset(isUsed, 0, 9 * sizeof(int));
	for(int j = 0; j < 9; j++){
	  if(board[i][j] == '.') continue;
	  if(isUsed[board[i][j] - 49]) return false; // [][]: [ , ]
	  isUsed[board[i][j] - 49] = 1;
	}
      }
      // check col
      for(int j = 0; j < 9; j++){
	memset(isUsed, 0, 9 * sizeof(int));
	for(int i = 0; i < 9; i++){
	  if(board[i][j] == '.') continue;
	  if(isUsed[board[i][j] - 49]) return false; // [][]: [ , ]
	  isUsed[board[i][j] - 49] = 1;
	}
      }
      // check square 
      for(int i = 0; i < 9; i += 3){
	for(int j = 0; j < 9; j += 3){
	  memset(isUsed, 0, 9 * sizeof(int)); // sizeOf: X
	  for(int m = 0; m < 3; m++){
	    for(int n = 0; n < 3; n++){
	      if(board[m + i][n + j] == '.') continue;
	      if(isUsed[board[m + i][n + j] - 49]) return false;
	      isUsed[board[m + i][n + j] - 49] = 1;
	    }
	  }
	}
      }
      return true;

    }
};
