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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>st;
        for (auto it : nums) {
            st.insert(it);
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr!= NULL) {
            if (st.find(curr->val) != st.end()) {
                if (prev == NULL) {
                    ListNode*temp=curr;
                    curr=curr->next;
                    head=head->next;
                    delete temp;
                }
                else
                {
                    ListNode*temp=curr;
                    curr=curr->next;
                    prev->next=curr;
                    delete temp;
                }
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};