/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode* removeElements(ListNode* head, int val) {
      if(head == NULL) return head;
      if(head->val == val) return removeElements(head->next, val);

      ListNode* curr = head;
      while(curr->next){
	if(curr->next->val == val) 
	  curr->next = curr->next->next;
	else
	  curr = curr->next;
      }
      return head;
    }
};;
