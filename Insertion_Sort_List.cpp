/*
 * Sort a linked list using insertion sort.
 */
class Solution {
  public:
    ListNode* insertionSortList(ListNode* head) {
      ListNode *newHead = new ListNode(INT_MIN);
      while(head) {
	ListNode *cur = head;
	ListNode *p = newHead;
	head = head->next;
	while(p->next && p->next->val<=cur->val) 
	  p = p->next;
	cur->next = p->next;
	p->next = cur;
      }

      head = newHead->next;
      delete newHead;
      return head;
    }
};
// v2
class Solution {
  public:
    ListNode* insertionSortList(ListNode* head) {
      if(!head || !head->next) return head;
      ListNode pre(0);
      ListNode* p = &pre;
      while(head) {
	p = &pre;
	while(p->next && p->next->val < head->val) {
	  p = p->next;
	}
	auto temp = head->next;
	head->next = p->next;
	p->next = head;
	head = temp;
      }
      return pre.next;
    }
};
//v3
class Solution {
  public:
    ListNode* insertionSortList(ListNode* head) {
      ListNode pre(0);
      ListNode* p;
      while(head) {
	p = &pre;
	while(p->next && p->next->val < head->val) {
	  p = p->next;
	}
	auto temp = head->next;
	head->next = p->next;
	p->next = head;
	head = temp;
      }
      return pre.next;
    }
};
