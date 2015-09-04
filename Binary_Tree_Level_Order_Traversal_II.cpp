/*
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
 * (ie, from left to right, level by level from leaf to root).
 */
class Solution {
  public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>> result;
      if(!root) return result;
      vector<TreeNode*> *curr = new vector<TreeNode*>();
      vector<TreeNode*> *next = new vector<TreeNode*>();
      curr->push_back(root);
      while(!curr->empty()){
	vector<int> currval;
	for(int i = 0; i < curr->size(); i++){
	  TreeNode* node = (*curr)[i];
	  currval.push_back(node->val);
	  if(node->left) next->push_back(node->left);
	  if(node->right) next->push_back(node->right);
	}
	result.insert(result.begin(), currval);
	vector<TreeNode*> *temp = curr;
	curr = next;
	next = temp;
	next->clear();
      }
      return result;
    }
};
