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
    int maxPathSum(TreeNode* root) {
      int maxXroot = INT_MIN;
      int maxToEnd = getMax(root, maxXroot);
      return max(maxToEnd, maxXroot);
    }
    int getMax(TreeNode* root, int& maxXroot){
      if(root == NULL) return 0;
      int left = getMax(root->left, maxXroot);
      int right = getMax(root->right, maxXroot);
      int maxXrootCurr = root->val; // current maxXroot, calculated from maxToEnd
      maxXrootCurr = max(maxXrootCurr, maxXrootCurr + left);
      maxXrootCurr = max(maxXrootCurr, maxXrootCurr + right);
      maxXroot = max(maxXroot, maxXrootCurr); // refresh all maxXroot
      return max(root->val, max(root->val + left, root->val + right)); // root node, or root + one of its sub tree
    }
};
