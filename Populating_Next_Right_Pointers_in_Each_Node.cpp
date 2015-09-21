/*
 * Populate each next pointer to point to its next right node. 
 * If there is no next right node, the next pointer should be set to NULL.
 * You may assume that it is a perfect binary tree 
 */
class Solution {
  public:
    void connect(TreeLinkNode *root) {
      if (!root || !root->left)  return;

      auto parent = root, son = root->left;

      while (son)
      {
	auto back = son;

	while (son)
	{
	  son->next = parent->right;
	  son = son->next;
	  parent = parent->next;
	  son->next = parent?parent->left:nullptr;
	  son = son->next;
	}

	parent = back;
	son = parent->left;
      }
    }
};
// v2
class Solution {
  public:
    void connect(TreeLinkNode *root) {
      if(!root || !root->left) return;
      TreeLinkNode* parent = root, *son = root->left;
      while(son) {
	auto temp = son;
	while(son) {
	  son->next = parent->right;
	  son = son->next;
	  parent = parent->next;
	  son->next = parent ? parent->left : NULL;
	  son = son->next;
	}
	parent = temp;
	son = parent->left;
      }
    }
};
// v3
class Solution {
  public:
    void connect(TreeLinkNode *root) {
      if(!root || !root->left) return;
      auto parent = root, child = root->left;
      while(child) {
	auto temp = child;
	while(child) {
	  child->next = parent->right;
	  child = child->next;
	  parent = parent->next;
	  child->next = parent ? parent->left : NULL;
	  child = child->next;
	}
	parent = temp;
	child = parent->left;
      }
    }
};
