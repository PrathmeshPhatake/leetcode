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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode*temp=head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        int part = len / k;
        int rem = len % k;
        vector<ListNode*> ans;
        while (k--) {
            int total = part;
            if (rem > 0) {
                total += 1;
                rem--;
            }
            ListNode* curr = head;
            ListNode* prev = NULL;
            while (total-- && curr != NULL) {
                prev = curr;
                curr = curr->next;
            }

            

            if (head != NULL) {
                prev->next = NULL;
                ans.push_back(head);
                head = curr;
            } else {
                ans.push_back(NULL);
            }
        }
        return ans;
    }
};
