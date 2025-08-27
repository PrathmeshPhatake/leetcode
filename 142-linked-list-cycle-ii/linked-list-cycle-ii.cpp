/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>st;
        int index=0;
        while(head!=NULL)
        {
            if(st.count(head))
            {
                return head;
            }
            st[head]=index;
            index++;
            head=head->next;
        }
        return NULL;
    }
};