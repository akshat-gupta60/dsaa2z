/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node* , Node*>m;
        Node* head1=head;
        Node* head2=head;

        while(head!=NULL){
            Node* node= new Node(head->val);

            m[head]=node;
            head=head->next;
        }

        while(head1!=NULL){
            m[head1]->next= m[head1->next];
            m[head1]->random=m[head1->random];
            head1=head1->next;
        }

        return m[head2];

        
    }
};