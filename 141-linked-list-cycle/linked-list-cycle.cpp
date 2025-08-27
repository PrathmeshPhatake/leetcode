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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        ListNode*prev=head;
        ListNode*curr=head->next;
        while(curr->next!=NULL && prev!=curr){
            curr=curr->next;
            if(curr->next!=NULL)curr=curr->next;
            prev=prev->next;
        }
        if(curr==prev) return true;
        return false;
    }
};