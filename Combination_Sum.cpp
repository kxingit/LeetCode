class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> result;
      vector<int> solution;
      int position = 0;
      int sum = 0;
      sort(candidates.begin(), candidates.end());
      combSum(candidates, position, sum, target, solution, result);
      return result;
    }
    void combSum(vector<int>& candidates, int& position, int& sum, int target, 
	vector<int>& solution, vector<vector<int>>& result){ // note: use pointers
      if(sum > target) return;
      if(sum == target){
	result.push_back(solution);
	return;
      }
      for(int i = position; i < candidates.size(); i++){ // i: pick a new number
	sum += candidates[i];
	solution.push_back(candidates[i]);
	combSum(candidates, i, sum, target, solution, result);
	solution.pop_back();
	sum -= candidates[i];
      }
    }
};
