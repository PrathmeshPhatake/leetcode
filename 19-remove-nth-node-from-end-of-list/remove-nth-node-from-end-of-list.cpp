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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode*temp=head;
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        int index=0;
        if(n==cnt)
        {
            ListNode*temp=head->next;
            delete head;
            return temp;
        }
        ListNode*curr=head;
        ListNode*prev=NULL;
        while(index<(cnt-n))
        {
            index++;
            prev=curr;
            curr=curr->next;
        }
        if(prev->next!=NULL)
        {
            prev->next=curr->next;
        }
        delete curr;
        return head;

    }
};