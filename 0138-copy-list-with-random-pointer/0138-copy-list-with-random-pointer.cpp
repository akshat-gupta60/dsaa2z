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
        

        //step1 insert dummy nodes

        Node* temp=head;

        while(temp!=NULL){
            Node* newNode= new Node(temp->val);

            newNode->next=temp->next;
            temp->next= newNode;
            temp=temp->next->next;
        }


        //step 2 pointer random pointers

        temp=head;

        while(temp!=NULL){
            Node* dummy= temp->next;
            if(temp->random!=NULL){
                dummy->random= temp->random->next;
            }
            else{
                dummy->random=NULL;
            }
            temp=temp->next->next;
            
        }

        //adjusting next pointers

        Node* dum= new Node(-1);
        Node* res=dum;
        temp=head;

        while(temp!=NULL){
            dum->next= temp->next;
            temp->next=temp->next->next;

            dum=dum->next;
            temp=temp->next;
        }

        return res->next;
    }
};