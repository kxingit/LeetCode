/*
 * Given a binary tree, return all root-to-leaf paths.
 */
class Solution {
  public:
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string> result;
      string solution;
      if(root == NULL) return result;
      getPaths(root, solution, result);
    }
    void getPaths(TreeNode* root, string& solution, vector<string> &result){
      solution += to_string(root->val);
      string temp = solution;
      if(root->left){
	solution += "->";
	getPaths(root->left, solution, result);
	solution = temp;
      }
      if(root->right){
	solution += "->";
	getPaths(root->right, solution, result);
	solution = temp;
      }
      if(!root->left && !root->right){
	result.push_back(solution);
      }
      return;
    }
};
