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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            delete head;
            return NULL;
        }
        int n=0;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            n++;
        }
        int cnt=0;
        ListNode*prev=NULL;
        ListNode*curr=head;
        while(cnt<n/2  )
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        // if it is a middle node
        if(prev!=NULL)
        {
            prev->next=curr->next;
        }
        
        delete curr;
        return head;
    }
};