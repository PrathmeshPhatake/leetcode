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
        if(l1==NULL && l2==NULL)
        {
            return NULL;
        }
        
        ListNode*temp1=l1;
        ListNode*temp2=l2;
        ListNode*head1=new ListNode(1);
        ListNode*head=head1;
        int carry=0;
        while(temp1!=NULL && temp2!=NULL)
        {
            int sum=temp1->val+temp2->val+carry;
            carry=sum/10;
            ListNode*insert=new ListNode(sum%10);
            head->next=insert;
            head=insert;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL )
        {
            int sum=temp1->val+carry;
            carry=sum/10;
             ListNode*insert=new ListNode(sum%10);
            head->next=insert;
            head=insert;
            temp1=temp1->next;
            
        }
        while( temp2!=NULL)
        {
            int sum=temp2->val+carry;
            carry=sum/10;
            ListNode*insert=new ListNode(sum%10);
            head->next=insert;
            head=insert;
            
            temp2=temp2->next;
        }
        if(carry>0)
        {
            ListNode*insert=new ListNode(carry);
            head->next=insert;
        }
        return head1->next;
    }
};