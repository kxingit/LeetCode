/* Given an array where elements are sorted in ascending order, 
 * convert it to a height balanced BST.
 */
class Solution {
  public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return buildTree(nums, 0, nums.size() - 1);
    }
    TreeNode* buildTree(vector<int>& nums, int start, int end){
      if(start > end) return NULL;
      int mid = (start + end) / 2;
      TreeNode* root = new TreeNode(nums[mid]);
      if(start == end) return root;
      root->left = buildTree(nums, start, mid - 1);
      root->right = buildTree(nums, mid + 1, end);
    }
};
