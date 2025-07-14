class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num=0;
        ListNode* temp = head;
        while (temp != NULL) {
           num=(num<<1 )|temp->val;
           temp=temp->next;
        }
        return num;
    }
};
