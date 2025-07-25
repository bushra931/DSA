/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr) return nullptr;
        ListNode *a=headA;
        ListNode *b=headB;
        while(a!=b){
            a=a==nullptr?headA:a->next;
            b=b==nullptr?headB:b->next;
        }
        return a;
        
    }
};