/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    bool hasPathSum(TreeNode* root, int sum) {
      return pathSum(root, 0, sum);
    }

    bool pathSum(TreeNode* root, int currSum, int sum){
      if(root == NULL) return 0;
      currSum += root->val;
      if(root->left == NULL && root->right == NULL){
	if(currSum == sum) return true;
	else return false;
      }
      return pathSum(root->left, currSum, sum) 
	|| pathSum(root->right, currSum, sum);
    }
};
