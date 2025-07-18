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
    struct comp{
        bool operator()(ListNode* a,ListNode* b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> minheap;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr){
                minheap.push(lists[i]);
            }
        }
        ListNode* dummyhead=new ListNode();
        ListNode* tail=dummyhead;
        while(!minheap.empty()){
            ListNode* curr=minheap.top();
            tail->next=curr;
            minheap.pop();
            tail=tail->next;
            if(curr->next!=nullptr){
                minheap.push(curr->next);
            }
        }
        return dummyhead->next; 
    }
};