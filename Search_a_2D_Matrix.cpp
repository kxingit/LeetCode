class Solution {
  public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
      // binary search is more efficient
      // consider the matrix as one sorted array
      if(!&matrix) return 0;  // the simplest way to judge if there is at leat 1 row and 1 col
      int m = matrix.size(), n = matrix[0].size();
      int istart = 0, iend = m*n - 1, imiddle, middle;
      while(istart <= iend){
	imiddle = (istart + iend) / 2;
	middle = matrix[imiddle / n][imiddle % n];
	if(target == middle) return 1;
	else if(target < middle) iend = imiddle - 1;
	else istart = imiddle + 1;
      }
      return 0;

    }
};
