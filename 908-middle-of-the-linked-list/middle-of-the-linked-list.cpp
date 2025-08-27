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
    ListNode* middleNode(ListNode* head) {
        ListNode*curr=head;
        ListNode*prev=curr;
        int count=0;
        while(curr->next!=NULL)
        {
            if(curr->next!=NULL)
            {
                curr=curr->next;
                count++;
            }
            if(curr->next!=NULL)
            {
                curr=curr->next;
                prev=prev->next;
                count++;
            }
        }

        return count%2==0?prev:prev->next;
    }
};