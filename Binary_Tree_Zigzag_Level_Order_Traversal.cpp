/*
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. 
 * (ie, from left to right, then right to left for the next level and alternate between).
 */
class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> result;
      if(!root) return result;
      vector<TreeNode*> *curr = new vector<TreeNode*>();
      vector<TreeNode*> *next = new vector<TreeNode*>();
      curr->push_back(root);
      int level = 1;
      while(!curr->empty()){
	vector<int> currval;
	for(int i = 0; i < curr->size(); i++){
	  TreeNode* node = (*curr)[i];
	  if(level % 2) currval.push_back(node->val);
	  else currval.insert(currval.begin(), node->val);
	  if(node->left) next->push_back(node->left);
	  if(node->right) next->push_back(node->right);
	}
	result.push_back(currval);
	curr->clear();
	vector<TreeNode*> *temp = curr;
	curr = next;
	next = temp;
	level++;
      }
      return result;
    }
};
