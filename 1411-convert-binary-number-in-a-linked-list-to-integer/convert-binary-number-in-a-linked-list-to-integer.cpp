class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string str = "";
        ListNode* temp = head;
        while (temp != NULL) {
            str += (temp->val + '0'); 
            temp = temp->next;
        }

        int num = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '1') {
                num += pow(2, str.size() - 1 - i); 
            }
        }
        return num;
    }
};
