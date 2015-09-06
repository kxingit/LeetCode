/*
 * Numbers can be regarded as product of its factors. For example,
 * 8 = 2 x 2 x 2;
 *  = 2 x 4.
 */
class Solution {
  public:
    vector<vector<int>> getFactors(int n) {
      vector<vector<int>> result;
      vector<int> solution;
      genSolution(n, solution, result);
      return result;
    }
    void genSolution(int n, vector<int> &solution, vector<vector<int>> &result){
      int i = solution.empty() ? 2 : solution.back();
      for(; i <= n / i; i++){
	if(n % i == 0){ // i is a solution
	  solution.push_back(i);
	  solution.push_back(n / i);
	  result.push_back(solution);
	  solution.pop_back();
	  genSolution(n / i, solution, result);
	  solution.pop_back();
	}
      }
    }
};
// v2
class Solution {
  public:
    vector<vector<int>> getFactors(int n) {
      vector<vector<int>> result;
      vector<int> solution;
      findSolution(n, solution, result);
      return result;
    }
    void findSolution(int n, vector<int> &solution, vector<vector<int>> &result) {
      int start = solution.empty() ? 2 : solution.back();
      for(int i = start; i <= n / i; i++) {
	if(n % i == 0) {
	  solution.push_back(i);
	  solution.push_back(n / i);
	  result.push_back(solution);
	  solution.pop_back();
	  findSolution(n / i, solution, result);
	  solution.pop_back();
	}
      }
      return;
    }
};
