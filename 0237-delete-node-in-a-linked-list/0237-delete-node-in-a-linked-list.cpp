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
    void deleteNode(ListNode* node) {
        
        ListNode*n1=NULL;
        while(node->next!=NULL){

            n1=node;
            ListNode* n2=node->next;
            node->val=n2->val;
            n2->val=n1->val;
            node=n2;

        }
        n1->next=NULL;
        
        return;
    }
};