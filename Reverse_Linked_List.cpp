/**
 * Reverse Linked List
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
      if(head == NULL || head->next == NULL) return head;
      ListNode* newHead = NULL;

      while(head){
	ListNode* temp = head;
	head = head->next;
	temp->next = newHead;
	newHead = temp;
      }
      return newHead;
    }
};
