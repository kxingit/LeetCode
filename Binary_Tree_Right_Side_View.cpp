/* 
 * Given a binary tree, imagine yourself standing on the right side of it, 
 * return the values of the nodes you can see ordered from top to bottom.
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
	vector<int> currval;
	for(int i = 0; i < curr->size(); i++){
	  auto node = (*curr)[i];
	  currval.push_back(node->val);
	  if(node->left) next->push_back(node->left);
	  if(node->right) next->push_back(node->right);
	}
	result.push_back(currval);
	swap(curr, next);
	next->clear();
      }
      return result;
    }
};
// recursive
class Solution {
  public:
    vector<int> rightSideView(TreeNode* root) {
      vector<vector<int>> result;
      vector<int> ret;
      trans(root, 1, result);
      for(int i = 0; i < result.size(); i++){
	ret.push_back(result[i][result[i].size() - 1]);
      }
      return ret;
    }
    void trans(TreeNode* &root, int level, vector<vector<int>> &result) {
      if(!root) return;
      if(result.size() < level) result.push_back(vector<int>());
      result[level - 1].push_back(root->val);
      trans(root->left, level + 1, result);
      trans(root->right, level + 1, result);
    }
};
