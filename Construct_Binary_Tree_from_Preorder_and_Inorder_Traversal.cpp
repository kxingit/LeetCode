/**
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * Note:
 * You may assume that duplicates do not exist in the tree.
 */
class Solution {
  public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      if(inorder.size() != preorder.size()) return NULL;
      return buildT(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildT(vector<int>& preorder, int preL, int preR, vector<int>& inorder, int inL, int inR){
      if(preL > preR || inL > inR) return NULL;
      TreeNode* root = new TreeNode(preorder[preL]);
      int pos = -1;
      for(int i = inL; i <= inR; i++){ // <= !!!! instead of <
	if(inorder[i] == root->val){
	  pos = i;
	  break;
	} 
      }
      if(pos == -1) return NULL;
      // int leftLength = pos - inL;
      // int rightLength = inR - pos;
      root->left = buildT(preorder, preL + 1, pos - inL + preL, inorder, inL, pos-1);
      root->right = buildT(preorder, preL + pos - inL + 1, preR, inorder, pos+1, inR);
      return root;
    }
};
