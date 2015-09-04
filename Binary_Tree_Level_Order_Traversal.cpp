/*
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 */
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> result;
      if(!root) return result;
      vector<TreeNode*> *curr = new vector<TreeNode*>();
      vector<TreeNode*> *next = new vector<TreeNode*>();
      curr->push_back(root);
      while(!curr->empty()){
	vector<int> currval; // current level values
	for(int i = 0; i < curr->size(); i++){
	  TreeNode* node = (*curr)[i];
	  currval.push_back(node->val);
	  if(node->left) next->push_back(node->left);
	  if(node->right) next->push_back(node->right);
	}
	result.push_back(currval);
	vector<TreeNode*> *temp = curr;
	curr = next;
	next = temp;
	next->clear();
      }
      return result;
    }
};
