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
    vector<int> postorderTraversal(TreeNode *root) {
      vector<int> result;
      post(root, result);
      return result;
    }
    void post(TreeNode *root, vector<int> &result){
      if(root == NULL) return;
      post(root->left, result);
      post(root->right, result);
      result.push_back(root->val);
    }
};
