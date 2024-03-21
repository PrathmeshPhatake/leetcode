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
    ListNode* oddEvenList(ListNode* head) {
        //check head is present or not 
        if(!head || !head->next)
        {
            return head;
        }
        ListNode*odd=head;
        ListNode*even=head->next;
        //it store head of even list 
        ListNode*evenhead=even;
        while(even!=NULL  &&even->next!=NULL)
        {
            //get odd node of list 
            odd->next=even->next;
            odd=odd->next;
            
            //get even no node 
            even->next=odd->next;
            even=even->next;
        }
        //conect head of odd list to even
        odd->next=evenhead;
        return head;
    }
};