/*
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * Recover the tree without changing its structure.
 */
class Solution {
  public:
    void recoverTree(TreeNode* root) {
      vector<TreeNode*> nodes;
      vector<int> values;
      inorder(root, nodes, values);
      sort(values.begin(), values.end());
      for(int i = 0; i < values.size(); i++)
	nodes[i]->val = values[i];
    }
    void inorder(TreeNode* root, vector<TreeNode*> &nodes, vector<int> &values){
      if(root == NULL){
	// nodes.push_back(root);
	return;
      }
      inorder(root->left, nodes, values);
      nodes.push_back(root);
      values.push_back(root->val);
      inorder(root->right, nodes, values);
    }
};
