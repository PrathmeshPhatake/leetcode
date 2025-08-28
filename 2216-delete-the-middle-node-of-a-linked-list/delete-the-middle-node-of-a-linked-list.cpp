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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head;
        if(head==NULL || head->next==NULL)return NULL;
        int count = 0;
        while (curr->next!= NULL) {
            curr = curr->next;
            count++;
            if (curr->next!= NULL) {
                curr = curr->next;
                prev = prev->next;
                count++;
            }
            else 
            {
                prev = prev->next;
            }
        }
        ListNode*temp=head;
        while(temp->next!=prev)
        {
            temp=temp->next;

        }
        temp->next=prev->next;
        return head;

    }

};