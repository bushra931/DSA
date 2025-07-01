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
        // Insert a copy of each node in between the original nodes
    void insertCopyInBetween(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextElement = temp->next;
            // Create a new node with the same data
            Node* copy = new Node(temp->val);
            
            copy->next = nextElement;
            
            temp->next = copy;
            
            temp = nextElement;
        }
    }

    // Function to connect random pointers of the copied nodes
    void connectRandomPointers(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            // Access the copied node
            Node* copyNode = temp->next;
            
            /*If the original node has a random pointer
            point the copied node's random to the 
            corresponding copied random node
            set the copied node's random to null 
            if the original random is null*/
            if (temp->random) {
                
                copyNode->random = temp->random->next;
            } else {
                
                copyNode->random = NULL;
            }
            
            // Move to next original node
            temp = temp->next->next;
        }
    }
        // Function to retrieve the deep copy of the linked list
    Node* getDeepCopyList(Node* head) {
        Node* temp = head;
        // Create a dummy node
        Node* dummyNode = new Node(-1);
        // Initialize a result pointer
        Node* res = dummyNode;

        while (temp != NULL) {
            /*Creating a new List by 
            pointing to copied nodes*/
            res->next = temp->next;
            res = res->next;

            /*Disconnect and revert back 
            to the initial state of the 
            original linked list*/
            temp->next = temp->next->next;
            temp = temp->next;
        }
        
        /*Return the deep copy 
        of the list starting 
        from the dummy node*/
        return dummyNode->next;
    }

    Node* copyRandomList(Node* head) {
        // If the original list is empty, return null
        if (!head) return nullptr;

        // Insert nodes in between
        insertCopyInBetween(head);
        // Connect random pointers
        connectRandomPointers(head);
        // Retrieve deep copy of inked list
        return getDeepCopyList(head);
        
    }
};