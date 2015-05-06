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
    ListNode *detectCycle(ListNode *head) {
      if(!head || !head->next) return NULL; // make sure line 16 can be excuted 
      ListNode *slow = head, *fast = head, *slow2;
      while(fast && fast->next){
	slow = slow->next;
	fast = fast->next->next;
	if(fast == slow) break;
      }
      if(!fast || !fast->next) return NULL;   // judge which caused the while loop breaks
      slow2 = head;   // set another slow pointer from the begining
      // if(slow2->next == slow) return slow2;
      while(slow2 != slow){   // where they meet will be the start 
	slow = slow->next;
	slow2 = slow2->next;
      }
      return slow2;
    }
};
