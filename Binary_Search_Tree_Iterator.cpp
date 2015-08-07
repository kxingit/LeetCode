/**
 * Note: next() and hasNext() should run in average O(1) time 
 * and uses O(h) memory, where h is the height of the tree.
 * http://yuanhsh.iteye.com/blog/2173429
 */
class BSTIterator {
  public:
    queue<TreeNode *> qt;
    BSTIterator(TreeNode *root) {
      if (root == nullptr) {
	return;
      }
      stack<TreeNode *> tmp;
      TreeNode* t = root;
      while (t || tmp.size() > 0) {
	while (t != nullptr){
	  tmp.push(t);
	  t = t->left;
	}
	t = tmp.top();
	tmp.pop();
	qt.push(t);
	t = t->right;
      }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
      return !qt.empty();
    }

    /** @return the next smallest number */
    int next() {
      TreeNode* tmp =  qt.front();
      qt.pop();
      return tmp->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
