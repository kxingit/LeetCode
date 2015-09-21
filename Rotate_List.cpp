/*
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 */
class Solution {
  public:
    ListNode* rotateRight(ListNode* head, int k) {
      if(!head || !head->next) return head;
      int len = 1;
      ListNode* p = head;
      while(p->next) {
	p = p->next;
	len++;
      }
      int step = len - k % len;
      p->next = head;
      for(int i = 0; i < step; i++) p = p->next;
      head = p->next;
      p->next = NULL;
      return head;
    }
};
// v2
class Solution {
  public:
    ListNode* rotateRight(ListNode* head, int k) {
      if(!head || !head->next) return head;
      ListNode* p = head;
      int len = 1;
      while(p->next) {
	p = p->next;
	len++;
      }
      int step = len - k % len;
      p->next = head; // make a circle
      for(int i = 0; i < step; i++) p = p->next;
      head = p->next;
      p->next = NULL;
      return head;
    }
};
// v3
class Solution {
  public:
    ListNode* rotateRight(ListNode* head, int k) {
      if(!head) return head;
      int len = 1;
      auto p = head;
      while(p->next) {
	p = p->next;
	len++;
      }
      p->next = head;
      int step = len - k % len;
      for(int i = 0; i < step; i++) {
	p = p->next;
      }
      head = p->next;
      p->next = NULL;
      return head;
    }
};
