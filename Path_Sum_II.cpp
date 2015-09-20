/* 
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 */
class Solution {
  public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      int currsum = 0;
      vector<int> solution;
      vector<vector<int>> result;
      if(!root) return result;
      path(root, sum, solution, result);
      return result;
    }

    void path(TreeNode* root, int sum, 
	vector<int>& solution, vector<vector<int>>& result){
      if(!root) return;
      sum -= root->val;
      solution.push_back(root->val);
      if(root->left == NULL && root->right == NULL){
	if(sum == 0) result.push_back(solution);
	// return; // no return, need pop_back
      }
      if(root->left) path(root->left, sum, solution, result);
      if(root->right) path(root->right, sum, solution, result);
      solution.pop_back();
    }
};
// v2
class Solution {
  public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      vector<vector<int>> res;
      vector<int> solution;
      int currSum = 0;
      path(root, currSum, sum, solution, res);
      return res;
    }
    void path(TreeNode* &root, int currSum, int sum, vector<int> &solution, vector<vector<int>> &res) {
      if(!root) return;
      currSum += root->val;
      solution.push_back(root->val);
      if(!root->left && !root->right) {
	if(currSum == sum) res.push_back(solution);
	// return;
      }
      if(root->left) {
	path(root->left, currSum, sum, solution, res);
      }
      if(root->right) {
	path(root->right, currSum, sum, solution, res);
      }
      solution.pop_back();
    }
};
