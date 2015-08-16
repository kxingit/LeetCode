/*
 * Kth Smallest Element in a BST 
 */
class Solution {
  public:
    int kthSmallest(TreeNode* root, int k) {
      int count = 0;
      TreeNode* p = root;
      stack<TreeNode*> st;
      while(p != NULL || !st.empty()){
	if(p != NULL){
	  st.push(p);
	  p = p->left;
	}
	else{
	  p = st.top();
	  st.pop();
	  if(++count == k) return p->val;
	  p = p->right;
	}
      }
    }
};
