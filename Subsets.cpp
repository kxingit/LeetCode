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


// v2
class Solution {
  public:
	vector<vector<int>> subsets(vector<int>& nums) {
	  vector<vector<int>> result;
	  vector<int> solution;
	  result.push_back(solution);
	  if(nums.size() == 0) return result;
	  getSub(nums, 0, solution, result);
	  return result;
	}

	void getSub(vector<int>& nums, int start, vector<int> &solution, vector<vector<int>>& result) {
	  for(int i = start; i < nums.size(); i++) {
		solution.push_back(nums[i]);
		result.push_back(solution);
		getSub(nums, i + 1, solution, result);
		solution.pop_back();
	  }
	}
};


// v3
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 8:55 - 8:58
        vector<vector<int>> res;
        vector<int> solution;
        getsub(nums, 0, solution, res);
        return res;
    }
    
    void getsub(vector<int> &nums, int start, vector<int> &solution, vector<vector<int>> &res) {
        res.push_back(solution);
        
        for(int i = start; i < nums.size(); i++) {
            solution.push_back(nums[i]);
            getsub(nums, i + 1, solution, res);
            solution.pop_back();
        }
    }
};
