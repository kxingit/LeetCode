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
// v2
class Solution {
  public:
    void flatten(TreeNode* root) {
      if(!root) return;
      TreeNode* left = root->left;
      TreeNode* right = root->right;
      flatten(left);
      flatten(right);
      if(!left) return;
      while(left->right) left = left->right;
      left->right = root->right;
      root->right = root->left;
      root->left = NULL;
    }
};
// v3
class Solution {
  public:
    void flatten(TreeNode* root) {
      if(!root) return;
      auto left = root->left;
      auto right = root->right;
      flatten(left);
      flatten(right);
      auto p = left;
      if(!p) return; // important
      while(p->right) p = p->right;
      p->right = root->right;
      root->right = left;
      root->left = NULL;
    }
};
// v4
class Solution {
  public:
    void flatten(TreeNode* root) {
      if(!root) return;
      flatten(root->left);
      flatten(root->right);
      auto p = root->left;
      if(!p) return;
      while(p->right) p = p->right;
      p->right = root->right;
      root->right = root->left;
      root->left = NULL;
    }
};
