class Node{
public:
    int key1,val;
    Node* next;
    Node* prev;
    Node(){
        key1=val=-1;
        next=prev=nullptr;
    }
    Node(int k,int value){
        key1=k;
        val=value;
        next=prev=nullptr;
    }
};
class LRUCache {
private: 
      map<int,Node*>mpp;
      int cap;
      Node* head;
      Node* tail;
      void deletenode(Node* node){
        Node* prevnode=node->prev;
        Node* nextnode=node->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
      }
      void insertafterhead(Node* node){
        Node* nextnode=head->next;
        head->next=node;
        nextnode->prev=node;
        node->prev=head;
        node->next=nextnode;
      }
public:
    LRUCache(int capacity) {
        cap=capacity;
        mpp.clear();
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;    
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node=mpp[key];
        int val=node->val;
        deletenode(node);
        insertafterhead(node);
        return val;    
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->val=value;
            deletenode(node);
            insertafterhead(node);
            return;
        } 
        if(mpp.size()==cap){
            Node* node=tail->prev;
            mpp.erase(node->key1);
            deletenode(node);
        }
        Node* newnode=new Node(key,value);
        mpp[key]=newnode;
        insertafterhead(newnode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */