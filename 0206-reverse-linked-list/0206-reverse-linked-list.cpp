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
    ListNode* reverseList(ListNode* head) {
        stack<int>st;
        ListNode* head1=head;

        while(head1!=NULL){
            st.push(head1->val);
            head1=head1->next;
        }
        head1=head;
        while(head1!=NULL){
            head1->val=st.top();
            st.pop();
            head1=head1->next;
        }
        return head;
    }
};