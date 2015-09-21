/*
 * Sort a linked list in O(n log n) time using constant space complexity.
 */
class Solution {
  public:
    ListNode* sortList(ListNode* head) {
      if(!head || !head->next) {
	return head;
      }
      ListNode* fast = head;
      ListNode* slow = head;
      while(fast->next && fast->next->next) {
	fast = fast->next->next;
	slow = slow->next;
      }
      ListNode* l1 = slow->next;
      ListNode* l2 = head;
      slow->next = NULL;
      auto p1 = sortList(l1);
      auto p2 = sortList(l2);
      return merge(p1, p2);
    }
    ListNode* merge(ListNode* p1, ListNode* p2) {
      ListNode* pre = new ListNode(0);
      ListNode* p = pre;
      while(p1 && p2) {
	if (p1->val < p2->val) {
	  p->next = p1;
	  p1 = p1->next;
	}
	else {
	  p->next = p2;
	  p2 = p2->next;
	}
	p = p->next;
      }
      if(p1) p->next = p1;
      else if(p2) p->next = p2;
      return pre->next;
    }
};
// v2
class Solution {
  public:
    ListNode* sortList(ListNode* head) {
      if(!head || !head->next) return head;
      auto slow = head, fast = head;
      while(fast->next && fast->next->next) {
	fast = fast->next->next;
	slow = slow->next;
      }
      auto l1 = head;
      auto l2 = slow->next;
      slow->next = NULL;
      auto p1 = sortList(l1);
      auto p2 = sortList(l2);
      return merge(p1, p2);
    }
    ListNode* merge(ListNode* p1, ListNode* p2) {
      ListNode* pre = new ListNode(0);
      ListNode* p = pre;
      while(p1 && p2) {
	if(p1->val < p2->val) {
	  p->next = p1;
	  p1 = p1->next;
	}
	else {
	  p->next = p2;
	  p2 = p2->next;
	}
	p = p->next;
      }
      if(p1) p->next = p1;
      if(p2) p->next = p2;
      return pre->next;
    }
};
// v3
class Solution {
  public:
    ListNode* sortList(ListNode* head) {
      if(!head || !head->next) return head;
      auto slow = head, fast = head;
      while(fast->next && fast->next->next) {
	fast = fast->next->next;
	slow = slow->next;
      }
      auto l1 = head;
      auto l2 = slow->next;
      slow->next = NULL;
      return merge(sortList(l1), sortList(l2));
    }
    ListNode* merge(ListNode* p1, ListNode* p2) {
      ListNode* pre = new ListNode(0);
      auto p = pre;
      while(p1 && p2) {
	if(p1->val < p2->val) {
	  p->next = p1;
	  p1 = p1->next;
	}
	else {
	  p->next = p2;
	  p2 = p2->next;
	}
	p = p->next;
      }
      if(p1) p->next = p1;
      if(p2) p->next = p2;
      return pre->next;
    }
};
// v4
class Solution {
  public:
    ListNode* sortList(ListNode* head) {
      if(!head || !head->next) return head;
      auto slow = head, fast = head;
      while(fast->next && fast->next->next) {
	fast = fast->next->next;
	slow = slow->next;
      }
      auto l1 = head;
      auto l2 = slow->next;
      slow->next = NULL;
      return merge(sortList(l1), sortList(l2));
    }
    ListNode* merge(ListNode* p1, ListNode* p2) {
      ListNode pre(0); // avoid using new
      auto p = &pre;
      while(p1 && p2) {
	if(p1->val < p2->val) {
	  p->next = p1;
	  p1 = p1->next;
	}
	else {
	  p->next = p2;
	  p2 = p2->next;
	}
	p = p->next;
      }
      if(p1) p->next = p1;
      if(p2) p->next = p2;
      return pre.next;
    }
};
