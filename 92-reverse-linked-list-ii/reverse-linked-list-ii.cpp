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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) {
            return nullptr;
        }
        if (left == right) {
            return head; 
        }

        ListNode* dummy = new ListNode(0);  
        dummy->next = head;
        ListNode* prev = dummy;

        // Move prev to the node before the `left` position
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        // `curr` will point to the starting node of the section to be reversed
        ListNode* curr = prev->next;
        ListNode* temp1 = curr;

        // Reverse the sublist
        ListNode* curr2 = curr;
        ListNode* prev2 = nullptr;
        for (int i = 0; i <= right - left; ++i) {
            ListNode* nextNode = curr2->next;
            curr2->next = prev2;
            prev2 = curr2;
            curr2 = nextNode;
        }

        // Connect the reversed part back to the list
        prev->next = prev2;  // Connect the node before `left` to the new head of the reversed sublist
        temp1->next = curr2; // Connect the tail of the reversed sublist to the node after `right`

        return dummy->next;  // Return the new head of the list
    }
};
