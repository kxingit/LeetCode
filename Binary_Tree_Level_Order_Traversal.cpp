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
// v2: recursion
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> result;
      trans(root, 1, result);
      return result;
    }
    void trans(TreeNode* root, int level, vector<vector<int>> &result) {
      if(!root) return;
      if(result.size() < level) result.push_back(vector<int>());
      result[level - 1].push_back(root->val);
      trans(root->left, level + 1, result);
      trans(root->right, level + 1, result);
    }
};