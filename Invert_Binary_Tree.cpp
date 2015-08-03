/**
 * Invert Binary Tree 
 * Trivia:
 * This problem was inspired by this original tweet by Max Howell:
 * https://twitter.com/mxcl/status/608682016205344768
 * Google: 90% of our engineers use the software you wrote (Homebrew), 
 * but you can’t invert a binary tree on a whiteboard so fuck off.
 */
class Solution {
  public:
    TreeNode* invertTree(TreeNode* root) {
      if(root == NULL) return root;

      TreeNode* temp = root->left;
      root->left = root->right;
      root->right = temp;
      invertTree(root->left);
      invertTree(root->right);
      return root;
    }
};
