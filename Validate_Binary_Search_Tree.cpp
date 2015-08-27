/*
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 */
class Solution {
  public:
    bool isValidBST(TreeNode* root) {
      return isVal(root, LONG_MIN, LONG_MAX);
    }
    bool isVal(TreeNode* root, long min, long max){
      if(root == NULL) return true;
      if(root->val <= min || root->val >= max) return false;
      if(root->left && !isVal(root->left, min, root->val)) return false;
      if(root->right && !isVal(root->right, root->val, max)) return false;
      return true;
    }
};
