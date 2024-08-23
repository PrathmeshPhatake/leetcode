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
        if(headA==NULL || headB==NULL)
        {
            return NULL;
        }
        ListNode *ptra=headA;
        ListNode *ptrb=headB;
        while(ptra!=ptrb)
        {
            ptra=(ptra==NULL)?headB:ptra->next;
            ptrb=(ptrb==NULL)?headA:ptrb->next;
        }
        return ptra;
        
    }
};