class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find the length of the list
        ListNode* curr = head;
        int length = 1;  // Start with 1 since we are at the first node
        while (curr->next != NULL) {
            curr = curr->next;
            length++;
        }
        
        // Step 2: Make the list circular
        curr->next = head;
        
        k=k%length;
        int rotate=length-k;
        curr=head;
        for(int i=1;i<rotate;i++)
        {
            curr=curr->next;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};
