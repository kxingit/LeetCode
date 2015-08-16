/* 
 * Given a set of distinct integers, nums, return all possible subsets.
 */

class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int> curr;
      vector<vector<int>> result;
      if(nums.size() == 0) return result;
      result.push_back(curr); // []
      sort(nums.begin(), nums.end());
      getSub(nums, 0, curr, result);
      return result;
    }
    void getSub(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& result){
      for(int i = start; i < nums.size(); i++){
	curr.push_back(nums[i]);
	result.push_back(curr);
	getSub(nums, i + 1, curr, result); // "i + 1"
	curr.pop_back();
      }
    }
};
