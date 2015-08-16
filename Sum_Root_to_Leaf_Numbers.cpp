/* 
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 */
class Solution {
  public:
    int sumNumbers(TreeNode* root) {
      int path = 0, sum = 0;
      getSum(root, path, sum);
      return sum;
    }
    void getSum(TreeNode* root, int path, int& sum){
      if(root == NULL) return;
      path = path * 10 + root->val;
      if(root->left == NULL && root->right == NULL){
	sum += path;
	return;
      }
      getSum(root->left, path, sum);
      getSum(root->right, path, sum);
    }
};
