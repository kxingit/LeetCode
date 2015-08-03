/* 
 * Given a binary tree where all the right nodes are either leaf nodes with a sibling
 * (a left node that shares the same parent node) or empty, flip it upside down and turn it into a 
 * tree where the original right nodes turned into left leaf nodes. Return the new root.
 */
class Solution {
  public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
      TreeNode *p = root, *parent = NULL, *parentRight = NULL;
      while (p) {
	TreeNode *next= p->left;
	p->left = parentRight;
	parentRight = p->right;
	p->right = parent;
	parent = p;
	p = next;
      }
      return parent;
    }
};
