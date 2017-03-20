/*
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 11:37 - 11:42
        if(!p && !q) return true;
        if((!p && q) || (p && !q)) {
            return false;
        }
        if(p->val != q->val) {
            return false;
        }
        if(!isSameTree(p->left, q->left) || !isSameTree(p->right, q->right)) {
            return false;
        }
        return true;
    }
};
