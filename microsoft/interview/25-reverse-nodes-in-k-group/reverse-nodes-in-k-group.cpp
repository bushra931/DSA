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
    int getlength(ListNode* head){
        ListNode* temp=head;
        int len=0;
        while(temp!=nullptr){
            len++;
            temp=temp->next;
        }
        return len;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* nextnode=curr->next;
        int pos=0;
        int len=getlength(head);
        if(len<k){
            return head;
        }
        while(pos<k){
            nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
            pos++;
        }
        ListNode* recursionans=nullptr;
        if(nextnode!=nullptr){
            recursionans=reverseKGroup(nextnode,k);
            head->next=recursionans;
        }
        return prev;  
    }
};