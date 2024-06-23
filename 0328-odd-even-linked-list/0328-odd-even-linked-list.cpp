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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL|| head->next==NULL) return head;

        if(head->next->next==NULL) return head;


        int ct=0;
        ListNode* head1=head;
        while(head1!=NULL){
            ct++;
            head1=head1->next;
        }
        if(ct%2==0){
             ListNode* curr=head;
        ListNode* forward=head->next;
        ListNode* temp_second=head->next;
        ListNode* temp_head=head;

        

        while(forward->next!=NULL){
            curr->next=forward->next;
            curr=forward;
            forward=forward->next;
        }

        curr->next=temp_second;

        return temp_head;
        }

         ListNode* curr=head;
        ListNode* forward=head->next;
        ListNode* temp_second=head->next;
        ListNode* temp_head=head;

        

        while(forward!=NULL){
            curr->next=forward->next;
            curr=forward;
            forward=forward->next;
        }

        curr->next=temp_second;

        return temp_head;


       
    }
};