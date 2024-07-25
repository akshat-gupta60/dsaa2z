class LRUCache {
public:

    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;

            Node (int _key, int _value){
                key=_key;
                val=_value;
            }
 
    };

    Node * head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);


    map<int,Node*>m;

    int cap;



    void insertAtHead(Node* node){
        Node* temp=head->next;


        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;

    }

    void deleteNode(Node* node){
        Node* nxtdel= node->next;
        Node* prvdel= node->prev;

        prvdel->next=nxtdel;
        nxtdel->prev=prvdel;
    }


    LRUCache(int capacity) {
         cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){

            Node* node=m[key];
            m.erase(key);
            deleteNode(node);
            insertAtHead(node);
            m[key]=head->next;
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {

        if(m.find(key)!=m.end()){
           
            deleteNode(m[key]);
            m.erase(key);
        }

        if(m.size()==cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* node=new Node(key,value);
        insertAtHead(node);
        m[key]=head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */