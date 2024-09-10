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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL)return head;
        ListNode*prev=head;
        ListNode*curr=head->next;
        while(curr!=NULL)
        {
            ListNode*temp=new ListNode(__gcd(prev->val,curr->val));
            prev->next=temp;
            temp->next=curr;
            prev=curr;
            curr=curr->next;
        }
        return head;
    }
};