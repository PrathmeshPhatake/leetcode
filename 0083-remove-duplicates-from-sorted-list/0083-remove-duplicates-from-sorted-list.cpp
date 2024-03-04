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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != NULL) {
            // Compare values to find duplicates
            while (curr != NULL && prev->val == curr->val) {
                curr = curr->next;
            }

            // Update next pointer of prev
            prev->next = curr;

            // Move prev and curr pointers forward
            prev = curr;
            if (curr != NULL) {
                curr = curr->next;
            }
        }

        return head;
    }
};
