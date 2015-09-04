/*
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 */
class Solution {
  public:
    void connect(TreeLinkNode *root) {
      if(!root) return;
      vector<TreeLinkNode*> *curr = new vector<TreeLinkNode*>();
      vector<TreeLinkNode*> *next = new vector<TreeLinkNode*>();
      curr->push_back(root);
      while(!curr->empty()){
	for(int i = 0; i < curr->size(); i++){
	  TreeLinkNode* node = (*curr)[i];
	  if(i == curr->size() - 1) node->next = NULL;
	  else node->next = (*curr)[i + 1];
	  if(node->left) next->push_back(node->left);
	  if(node->right) next->push_back(node->right);
	}
	vector<TreeLinkNode*> *temp = curr;
	curr = next;
	next = temp;
	next->clear();
      }
      return;
    }
};
