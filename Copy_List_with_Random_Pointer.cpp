/* 
 * A linked list is given such that each node contains an additional random 
 * pointer which could point to any node in the list or null.
 * Return a deep copy of the list.
 *
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
  public:
    RandomListNode *copyRandomList(RandomListNode *head) {
      if(head == NULL) return head;
      doubleNode(head); // copy this node to the next
      pointRandom(head); // fix random pointer
      RandomListNode* p = head;
      RandomListNode* q = head->next;
      splitList(head);
      return q;
    }
    void doubleNode(RandomListNode* head){ 
      RandomListNode* p = head;
      while(p){
	// RandomListNode* q = p; // wrong, should be hard copy
	RandomListNode* q = new RandomListNode(p->label);
	q->next = p->next;
	p->next = q;
	p = q->next;
      }
    }
    void pointRandom(RandomListNode* head){
      RandomListNode* p = head;
      while(p){
	RandomListNode* q = p->next;
	if(p->random) q->random = p->random->next;
	p = q->next;
      }
    }
    void splitList(RandomListNode* head){
      RandomListNode* p = head;
      while(p){
	RandomListNode* q = p->next;
	p->next = q->next;
	if(q->next) q->next = q->next->next; // !!! if(q->next)
	p = p->next;
      }
    }
};
