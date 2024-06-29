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

    void insert(ListNode*& anshead, ListNode*& anstail, int num) {
        if(anshead == nullptr) {
            anshead = new ListNode(num);
            anstail = anshead;
        } else {
            ListNode* node = new ListNode(num);
            anstail->next = node;
            anstail = anstail->next;
        }
    }

    ListNode* rev(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward = nullptr;

        while(curr != nullptr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    ListNode* sum(ListNode* head1, ListNode* head2) {
        int carry = 0;
        ListNode* anshead = nullptr;
        ListNode* anstail = nullptr;

        while(head1 != nullptr || head2 != nullptr || carry != 0) {
            int n1 = 0, n2 = 0;
            if(head1 != nullptr) {
                n1 = head1->val;
            }
            if(head2 != nullptr) {
                n2 = head2->val;
            }

            int sum = n1 + n2 + carry;
            insert(anshead, anstail, sum % 10);
            carry = sum / 10;

            if(head1 != nullptr) head1 = head1->next;
            if(head2 != nullptr) head2 = head2->next;
        }

        return anshead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 =(l1);
        ListNode* head2 = (l2);
        ListNode* head_sum = sum(head1, head2);
        return (head_sum);  // Reverse the result list to get the final sum in correct order
    }
};
