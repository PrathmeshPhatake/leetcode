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
ListNode*func(ListNode*curr,ListNode*prev)
{
    if(curr==NULL)
    {
        return prev;
    }
    ListNode*temp=new ListNode(curr->val);
    temp->next=prev;
    prev=temp;
    curr=curr->next;
    return func(curr,prev);
}
    bool isPalindrome(ListNode* head) {
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*revhead=func(curr,prev);
        while(head!=NULL && revhead!=NULL)
        {
            if(head->val!=revhead->val)
            {
                return false;
            }
            head=head->next;
            revhead=revhead->next;
        }
        return true;
    }
};