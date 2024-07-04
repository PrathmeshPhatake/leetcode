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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL) return NULL;
         head=head->next; // skip first zero 
        ListNode*dummy=new ListNode(0);
        //current for attached new node
        ListNode*current=dummy;
        int sum=0;
        while(head!=NULL)
        {
            if(head->val==0)
            {
                //crteate new node
                ListNode*temp=new ListNode(sum);
                current->next=temp;
                sum=0;
                current=current->next;
                
            }
            else
            {
                sum+=head->val;
            }
            head=head->next;
        }
        //skip first zero
        return dummy->next;
    }
};