/*
   You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

   You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 7:37 - 7:48
        ListNode* ret = new ListNode(0);
        ListNode* p = ret;
        int carry = 0;
        while(l1 && l2) {
            int val = l1->val + l2->val + carry;
            carry = val / 10;
            val = val % 10;
            p->next = new ListNode(val);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int val = l1->val + carry;
            carry = val / 10;
            p->next = new ListNode(val % 10);
            p = p->next;
            l1 = l1->next;
        }
        while(l2) {
            int val = l2->val + carry;
            carry = val / 10;
            p->next = new ListNode(val % 10);
            p = p->next;
            l2 = l2->next;
        }
        
        if(carry > 0) {
            p->next = new ListNode(carry);
        }
        
        return ret->next;
    }
};
