/* 
 * Given an index k, return the kth row of the Pascal's triangle.
 */
class Solution {
  public:
    vector<int> getRow(int rowIndex) {
      if(rowIndex == 0) return {1};
      vector<int> result(rowIndex + 1, 1);
      for(int i = 1; i <= rowIndex; i++){ // upto rowIndex
	for(int j = i - 1; j >= 1; j--){
	  result[j] = result[j - 1] + result[j]; // from back to front
	}
      }
      return result;
    }
};
