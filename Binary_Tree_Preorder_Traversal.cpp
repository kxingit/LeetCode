/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode *root) {
      vector<int> result;
      pre(root, result);
      return result;
    }

    void pre(TreeNode *root, vector<int> &result) {
      if(root == NULL) return;
      result.push_back(root->val);
      pre(root->left, result);
      pre(root->right, result);
    }
};
