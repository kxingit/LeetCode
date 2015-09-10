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
// v2
class Solution {
  public:
    int kthSmallest(TreeNode* root, int k) {
      stack<TreeNode*> st;
      int count = 0;
      while(root || !st.empty()){
	if(root) {
	  st.push(root);
	  root = root->left;
	}
	else {
	  root = st.top(); // all left has transversed 
	  st.pop();
	  count++;
	  if(count == k) return root->val;
	  root = root->right;
	}
      }
    }
};
