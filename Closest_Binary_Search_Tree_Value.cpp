/*
 * Given a non-empty binary search tree and a target value, 
 * find the value in the BST that is closest to the target.
 */
// int over flow!!
class Solution {
  public:
    int closestValue(TreeNode* root, double target) {
      TreeNode* kid; // next possbile node
      if(root->val - target < 0) kid = root->right;
      else kid = root->left;
      if(kid == NULL) return root->val;
      int newsolution = closestValue(kid, target);
      return abs(root->val - target) < abs(newsolution - target) ? root->val : newsolution;
    }
};
