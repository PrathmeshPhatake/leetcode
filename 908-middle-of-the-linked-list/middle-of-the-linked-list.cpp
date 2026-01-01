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
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode*prev=head;
        ListNode*curr=head->next;
        while(curr->next!=NULL){
            curr=curr->next;
            if(curr->next!=NULL)
            {
                curr=curr->next;
                prev=prev->next;
            }
        }
        return prev->next;
    }
};