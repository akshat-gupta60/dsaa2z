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
    ListNode* reverseKGroup(ListNode* head, int k) {
        

        if(head==NULL) return NULL;

        ListNode* head1=head;
        int ct1=0;

        while(head1!=NULL){
            ct1++;
            head1=head1->next;
        }
        if(ct1<k) return head;


        ListNode* curr=head;
        ListNode*prev=NULL;
        ListNode* forward=head;
        int ct=0;


        while(curr!=NULL && ct<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            ct++;
        }

       

        if(forward!=NULL){
            head->next=reverseKGroup(forward,k);
        }

        return prev;
    }
};