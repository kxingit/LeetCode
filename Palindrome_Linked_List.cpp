/* 
 * Given a singly linked list, determine if it is a palindrome.
 */
class Solution {
  public:
    bool isPalindrome(ListNode* head) {
      if(!head) return true;
      ListNode* curr = head; // head of new (reversed) list
      ListNode* newHead;
      while(curr){
	ListNode* temp = new ListNode(curr->val);
	temp->next = newHead;
	newHead = temp;
	curr = curr->next;
      }
      while(head){
	if(head->val != newHead->val){
	  return false;
	}
	head = head->next;
	newHead = newHead->next;
      }
      return true;
    }
};

/* O(n) time and O(1) space */
class Solution {
  public:
    bool isPalindrome(ListNode* head) {
      if(!head || !head->next) return true;
      ListNode* temp0 = head;
      int n = 0;
      while(temp0){
	n++;
	temp0 = temp0->next;
      }
      int mid = n / 2 + n % 2; // starting node for the 2nd half
      ListNode* curr = head;
      for(int i = 0; i < mid; i++){
	curr = curr->next;
      }
      ListNode* newHead = NULL; // "= NULL"!!!!
      while(curr){ // reverse the 2nd half
	ListNode* temp = curr->next;
	curr->next = newHead;
	newHead = curr;
	curr = temp;
      }
      while(newHead && head){
	if(newHead->val != head->val){
	  return false;
	}
	head = head->next;
	newHead = newHead->next;
      }
      return true;
    }
};
