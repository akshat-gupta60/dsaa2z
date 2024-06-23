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

    ListNode* cycledetect(ListNode* head){
          ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && slow!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast!=NULL) fast=fast->next;

            if(slow==fast) return slow;

        }

        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
      ListNode* cycle_node=cycledetect(head);

      if(cycle_node==NULL) return NULL;

      ListNode* slow=head;

      while(slow!=cycle_node){
        slow=slow->next;
        cycle_node=cycle_node->next;
      }

      return slow;
    }
};