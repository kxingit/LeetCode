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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      ListNode* node0 = new ListNode(-1); // initialization
      node0->next = head;
      ListNode* prev = node0;
      int k = m - 1;
      while(k > 0){
	k--;
	prev = prev->next;
      }

      k = n - m;
      ListNode* curr = prev->next;
      while(k > 0){
	k--;
	ListNode* currN = curr->next;
	ListNode* currNN = currN->next;
	ListNode* tmp = prev->next;
	prev->next = currN;
	currN->next = tmp;
	curr->next = currNN;
      }
      return node0->next;
    }
};
