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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        priority_queue<int,vector<int>,greater<int>>pq;
        while(head!=NULL)
        {
            pq.push(head->val);
            head=head->next;
        }
        ListNode*sorthead=new ListNode(pq.top());
        pq.pop();
        ListNode*sortpoint=sorthead;
        while(!pq.empty())
        {
            ListNode*temp=new ListNode(pq.top());
            pq.pop();
            sortpoint->next=temp;
            sortpoint=sortpoint->next;
        }
        return sorthead;
    }
};