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
// v3
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> res;
      if(!root) return res;
      vector<TreeNode*> thisLevel;
      vector<TreeNode*> nextLevel;
      thisLevel.push_back(root);
      while(!thisLevel.empty()) {
	vector<int> line;
	for(auto node : thisLevel) {
	  line.push_back(node->val);
	  if(node->left) nextLevel.push_back(node->left);
	  if(node->right) nextLevel.push_back(node->right);
	}
	thisLevel = nextLevel;
	nextLevel.clear();
	res.push_back(line);
      }
      return res;
    }
};
// v4
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> res;
      if(!root) return res;
      trans(root, 0, res);
      return res;
    }
    void trans(TreeNode* root, int level, vector<vector<int>>& res) {
      if(!root) return;
      if(level >= res.size()) res.push_back(vector<int>());
      res[level].push_back(root->val);
      trans(root->left, level + 1, res);
      trans(root->right, level + 1, res);
    }
};
