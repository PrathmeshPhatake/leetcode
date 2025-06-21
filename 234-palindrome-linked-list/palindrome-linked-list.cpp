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
    ListNode*reversecopy(ListNode* head)
    {
        ListNode* revhead=NULL;
        while(head)
        {
            ListNode*newNode=new ListNode(head->val);
            newNode->next=revhead;
            revhead=newNode;
            head=head->next;
        }
        return revhead;
    }
    bool isPalindrome(ListNode* head) {
        if(!head  ||!head->next) return true;
        ListNode*reverse=reversecopy(head);
        while(reverse && head && reverse->next!=NULL && head->next!=NULL )
        {
            if(head->val!=reverse->val)
            {
                return false;
            }
            head=head->next;
            reverse=reverse->next;
        }
        return true;
    }
};