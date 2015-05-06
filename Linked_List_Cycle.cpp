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
    bool hasCycle(ListNode *head) {
      ListNode *slow = head, *fast = head;
      if(!fast) return false; // empty node has no circle
      if(fast == fast->next) return true; // the node pointing to itself is a node

      while (fast && fast->next){ // if no circle, the while will break
	slow = slow->next;
	fast = fast->next->next;    
	if (fast == slow ) return true; // if there is a circle, fast will catch up slow
      }
      return false;
    }
};
