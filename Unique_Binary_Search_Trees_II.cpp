/*
 * Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    vector<TreeNode*> generateTrees(int n) {
      return *generate(1, n);
    }

    vector<TreeNode*>* generate(int start, int end){
      vector<TreeNode*>* result = new vector<TreeNode*>(NULL); // initialization pointer
      if(start > end){
	result->push_back(NULL);
	return result;
      }
      for(int i = start; i <= end; i++){
	vector<TreeNode*>* left = generate(start, i - 1);
	vector<TreeNode*>* right = generate(i + 1, end);
	for(int j = 0; j < left->size(); j++){
	  for(int k = 0; k < right->size(); k++){
	    TreeNode* root = new TreeNode(i);
	    root->left = (*left)[j];
	    root->right = (*right)[k];
	    result->push_back(root);
	  }
	}
      }
      return result;
    }
};
