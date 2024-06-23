/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp=head;
        int ct=0;
        while(temp!=NULL){
            ct++;
            temp=temp->next;

        }
        int node_deleted=ct-n;

        if(node_deleted==0){
            head=head->next;
            return head;
        }

        ListNode*prev=NULL;
        ListNode* curr=head;


        for(int i=0;i<node_deleted;i++){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        curr->next=NULL;
        return head;
    }
};