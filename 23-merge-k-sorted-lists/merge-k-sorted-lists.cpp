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
 struct comparator{
    bool operator()(ListNode* const& lhs,ListNode* const& rhs){
        return lhs->val > rhs->val;
    }
 };
class Solution {

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comparator>pq;
        //PUSH HEAD OF SUBLIST OF LIMKEDLIST 
        for(auto it:lists)
        {
            if(it!=nullptr)
           {
             pq.push(it);
            }
        }
        //using that head get push new value in queue
        //for addrese of first node
        ListNode dummy;
        ListNode* tail= &dummy;
        while(!pq.empty())
        {
            ListNode* node=pq.top();
            pq.pop();

            //linked node
            tail->next=node;
            tail=node;
            if(node->next != nullptr)
            {
                pq.push(node->next);
            }
        }
       return dummy.next;
    }
};