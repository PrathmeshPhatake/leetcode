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
struct comparelistNode{
 bool operator()(ListNode* const&a ,ListNode* const&b)
 {
    return a->val>b->val;
 }
};
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next==NULL)
        {
            return head;
        }
        priority_queue<ListNode*,vector<ListNode*>,comparelistNode>pq;
        ListNode*temp=head;
        while(temp)
        {
            pq.push(temp);
            temp=temp->next;
        }
        head=pq.top();
        pq.pop();
        ListNode*temp1=head;
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