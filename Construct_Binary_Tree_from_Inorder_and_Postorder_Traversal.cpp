/* 
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * You may assume that duplicates do not exist in the tree.
 */
class Solution {
  public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      int n = inorder.size();
      return build(inorder, 0, n - 1, postorder, 0, n - 1);
    }
    TreeNode* build(vector<int>& inorder, int s1, int e1, vector<int>& postorder, int s2, int e2){
      if(s1 > e1) return NULL;
      TreeNode* root = new TreeNode(postorder[e2]);
      int rootIndex = -1;
      for(int i = s1; i <= e1; i++){
	if(inorder[i] == postorder[e2]){
	  rootIndex = i;
	  break;
	}
      }
      if(rootIndex==-1) return NULL;
      int leftsize = rootIndex - s1;
      int rightsize = e1 - rootIndex;
      root->left = build(inorder, s1, rootIndex - 1, postorder, s2, s2 + leftsize - 1);
      root->right = build(inorder, rootIndex + 1, e1, postorder, e2 - rightsize, e2 - 1);
    }
};
