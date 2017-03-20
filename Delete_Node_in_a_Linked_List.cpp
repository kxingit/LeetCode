/**
 * Delete Node in a Linked List 
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    void deleteNode(ListNode* node) {
      node->val = node->next->val;
      node->next = node->next->next;
    }
};

// v2
public:
    void deleteNode(ListNode* node) {
        // 7:55 - 7:56
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
