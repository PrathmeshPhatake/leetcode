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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*ptra=l1;
        ListNode*ptrb=l2;
        ListNode*reshead=new ListNode(-1);
        ListNode*restail=reshead;
        int digit=0;
        while(ptra!=NULL && ptrb!=NULL)
        {
            int value=(ptra->val+ptrb->val)+digit;
            int unit=value%10;
            digit=value/10;
            ListNode*newnode=new ListNode(unit);
            restail->next=newnode;
            restail=newnode;
            ptra=ptra->next;
            ptrb=ptrb->next;
            
        }
        while(ptra!=NULL )
        {
            int value=(ptra->val)+digit;
            int unit=value%10;
            digit=value/10;
            ListNode*newnode=new ListNode(unit);
            restail->next=newnode;
            restail=newnode;
            ptra=ptra->next;            
        }
        while(ptrb!=NULL)
        {
            int value=(ptrb->val)+digit;
            int unit=value%10;
            digit=value/10;
            ListNode*newnode=new ListNode(unit);
            restail->next=newnode;
            restail=newnode;
            ptrb=ptrb->next;
            
        }
        if(digit>0)
        {
            ListNode*newnode=new ListNode(digit);
            restail->next=newnode;
            restail=newnode;
        }
        return reshead->next;
    }
};