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

    ListNode* reverse_LL(ListNode* head){

        if(head==NULL|| head->next==NULL) return head;
        ListNode *prev=NULL;
        ListNode* curr=head;
        ListNode* forward=NULL;

        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;

        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(slow!=NULL&& fast!=NULL){
            slow=slow->next;
            fast=fast->next;

            if(fast!=NULL){
                fast=fast->next;
            }
            
        }

        ListNode* rev_node=reverse_LL(slow);
        ListNode* temp1=head;
        while(temp1!=NULL && rev_node!=NULL){
            if(rev_node->val!=temp1->val){
                return false;
            }
            temp1=temp1->next;
            rev_node=rev_node->next;
        }

        return true;

    }
};