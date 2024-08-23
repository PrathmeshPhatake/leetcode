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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        stack<ListNode*>stq;
        ListNode*curr=head;
        while(curr)
        {
            stq.push(curr);
            curr=curr->next;
        }
        head=stq.top();
        stq.pop();
        curr=head;
        
        while(!stq.empty())
        {
            curr->next=stq.top();
            stq.pop();
            curr=curr->next;
        }
        curr->next=NULL;
        return head;

    }
};