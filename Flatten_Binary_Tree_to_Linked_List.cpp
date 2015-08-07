/**
 * Given a binary tree, flatten it to a linked list in-place.
 */
class Solution {
  public:
    void flatten(TreeNode* root) {
      if(root == NULL) return;
      if(root->left) flatten(root->left);
      if(root->right) flatten(root->right);
      TreeNode* p = root->left;
      if(p == NULL) return;
      while(p->right) p = p->right; // while(p): X
      p->right = root->right;
      root->right = root->left;
      root->left = NULL;
    }
};
