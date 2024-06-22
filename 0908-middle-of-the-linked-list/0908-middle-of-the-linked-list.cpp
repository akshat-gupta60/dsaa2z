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
    ListNode* middleNode(ListNode* head) {
        
        int ct=0;

        if(head==NULL) return head;
        ListNode* head1=head;


        while(head1!=NULL){
            ct++;
            head1=head1->next;
        }

        int mid_value=(ct/2);
        head1=head;

        while(head1!=NULL && mid_value){
            head1=head1->next;
            mid_value--;
        }
        return head1;
    }
};