/*
 * Find all possible combinations of k numbers that add up to a number n, 
 * given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 */
class Solution {
  public:
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>> result;
      vector<int> curr;
      DFS(k, n, 1, curr, result);
      return result;
    }
    void DFS(int k, int n, int start, vector<int> curr, vector<vector<int>>& result){
      if(curr.size() == k) {
	if(sumof(curr) == n) result.push_back(curr);
	return;
      }
      for(int i = start; i < 10; i++){
	curr.push_back(i);
	DFS(k, n, i + 1, curr, result);
	curr.pop_back();
      }
    }
    int sumof(vector<int> vec){
      int sum = 0;
      for(int i = 0; i < vec.size(); i++){
	sum += vec[i];
      }
      return sum;
    }
};
