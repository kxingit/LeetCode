/**
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 */
class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      int lenA = 0, lenB = 0;
      ListNode* temp = headA;
      while(temp){
	temp = temp->next;
	lenA++;
      }
      temp = headB;
      while(temp){
	temp = temp->next;
	lenB++;
      }
      if(lenA > lenB) return getIntersectionNode(headB, headA);
      for(int i = 0; i < lenB - lenA; i++){
	headB = headB->next;
      }
      while(headA){
	if(headA == headB) return headA;
	headA = headA->next;
	headB = headB->next;
      }
      return NULL;
    }
};
