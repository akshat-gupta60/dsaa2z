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


    ListNode* find_middle(ListNode* head){

        if(head==NULL|| head->next==NULL) return head;

        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            
        }
        return slow;
    }


    ListNode* merge(ListNode* head1, ListNode* head2){

        ListNode* node=new ListNode(-1);
        ListNode* temp=node;

        while(head1!=NULL && head2!=NULL){
            if(head1->val<=head2->val){
                node->next=head1;
                head1=head1->next;
                node=node->next;
            }
            else{
                node->next=head2;
                head2=head2->next;
                node=node->next;
            }
        }

        while(head1!=NULL){
            node->next=head1;
            head1=head1->next;
            node=node->next;
        }
         while(head2!=NULL){
            node->next=head2;
            head2=head2->next;
            node=node->next;
        }

        return temp->next;


    }

    ListNode* sortList(ListNode* head) {
        
        if(head==NULL|| head->next==NULL) return head;

        ListNode* middle_node=find_middle(head);

        ListNode* left_node=head;
        ListNode* right_node= middle_node->next;
        middle_node->next=NULL;

        ListNode* sorted_left=sortList(left_node);
        ListNode* sorted_right=sortList(right_node);

        return merge(sorted_left,sorted_right);
    }
};