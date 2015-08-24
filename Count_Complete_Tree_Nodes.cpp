/*
 * Given a complete binary tree, count the number of nodes.
 * In a complete binary tree every level, except possibly the last, is completely filled, 
 * and all nodes in the last level are as far left as possible. It can 
 */
class Solution {
  public:
    int countNodes(TreeNode* root) {
      if(!root) return 0;
      int lh = 0, rh = 0; // hight of left and right
      TreeNode* lnode = root, * rnode = root;
      while(lnode){
	lh++;
	lnode = lnode->left;
      }
      while(rnode){
	rh++;
	rnode = rnode->right;
      }
      if(lh == rh) return pow(2, lh) - 1; 
      return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
