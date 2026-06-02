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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* curr = new ListNode(0);
        ListNode* temphead = curr;
        while (l1 != NULL && l2 != NULL) {
            int rem = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            ListNode* temp = new ListNode(rem);
            curr->next = temp;
            curr = temp;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL ) {
            int rem = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            ListNode* temp = new ListNode(rem);
            curr->next = temp;
            curr = temp;
            l1 = l1->next;
        }
        while ( l2 != NULL) {
            int rem = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            ListNode* temp = new ListNode(rem);
            curr->next = temp;
            curr = temp;
            l2 = l2->next;
        }
        if(carry>0)
        {
            ListNode* temp = new ListNode(carry);
            curr->next=temp;
            curr=temp;
        }
        return temphead->next;
    }
};