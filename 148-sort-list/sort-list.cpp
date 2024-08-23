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
struct compareListNode{
    bool operator()(ListNode* const&a,ListNode* const&b)
    {
        return a->val >b->val;
    }
};
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next==NULL)
        {
            return  head;
        }
        priority_queue<ListNode*,vector<ListNode*>,compareListNode>pq;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            pq.push(temp);
            temp=temp->next;
        }
        head=pq.top();
        ListNode*temp1=head;
        pq.pop();
        while(!pq.empty())
        {
            ListNode*insert=pq.top();
            pq.pop();
            temp1->next=insert;
            temp1=insert;
        }
        temp1->next=NULL;
        return head;
        
    }
};