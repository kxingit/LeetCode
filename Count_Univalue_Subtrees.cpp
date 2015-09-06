/*
 * Given a binary tree, count the number of uni-value subtrees.
 * A Uni-value subtree means all nodes of the subtree have the same value.
 */
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
    int countUnivalSubtrees(TreeNode* root) {
      int result = 0;
      isU(root, result);
      return result;
    }
    bool isU(TreeNode* root, int &result){
      if(!root) return true;
      bool left = isU(root->left, result);
      bool right = isU(root->right, result);
      if(isSame(root, root->left, left)
	  && isSame(root, root->right, right)){
	result++;
	return true;
      }
      return false;
    }
    bool isSame(TreeNode* root, TreeNode* child, bool is_uni){
      return child == NULL || (is_uni && root->val == child->val);
    }
};
// v2
class Solution {
  public:
    int countUnivalSubtrees(TreeNode* root) {
      int result = 0;
      isU(root, result);
      return result;
    }
    bool isU(TreeNode* &root, int &result){
      if(!root) return true;
      bool left = isU(root->left, result);
      bool right = isU(root->right, result);
      if(isSame(root, root->left, left) && isSame(root, root->right, right)){
	result++;
	return true;
      }
      else return false;
    }
    bool isSame(TreeNode* &root, TreeNode* &child, bool is_child_u){
      if((!child || root->val == child->val ) && is_child_u) return true;
      else return false;
    }
};
