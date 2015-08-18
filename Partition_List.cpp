/*
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *You should preserve the original relative order of the nodes in each of the two partitions.
 */
class Solution {
  public:
    ListNode* partition(ListNode* head, int x) {
      ListNode *h1 = new ListNode(0);
      ListNode *h2 = new ListNode(0);
      ListNode *t2 = h2;
      h1->next = head;
      head = h1;

      while(head->next) {
	if(head->next->val<x)   // skip node
	  head = head->next;
	else {  // move node from h1 to h2
	  t2->next = head->next;
	  head->next = head->next->next;
	  t2 = t2->next;
	  t2->next = NULL;
	}
      }
      // connect two lists
      head->next = h2->next;
      head = h1->next;
      delete h1;
      delete h2;
      return head;
    }
};
