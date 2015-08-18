/*
 * Given a collection of candidate numbers (C) and a target number (T), 
 * find all unique combinations in C where the candidate numbers sums to T.
 * Each number in C may only be used once in the combination.
 */
class Solution {
  public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<vector<int>> result;
      vector<int> solution;
      int sum = 0;
      sort(candidates.begin(), candidates.end());
      DFS(candidates, target, 0, sum, solution, result);
      return result;
    }
    void DFS(vector<int>& cand, int target, int start, int& sum,
	vector<int>& solution, vector<vector<int>>& result){
      if(sum > target) return; // pruning
      // if(start == cand.size()){ // wrong
      if(sum == target){
	result.push_back(solution);
	return;
      }
      for(int i = start; i < cand.size(); i++){
	solution.push_back(cand[i]);
	sum += cand[i];
	DFS(cand, target, i + 1, sum, solution, result); // "i + 1"
	solution.pop_back();
	sum -= cand[i]; // restore sum too!!
	while(i + 1 < cand.size() && cand[i] == cand[i + 1]) i++;
      }
    }
    };
