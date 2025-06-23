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
ListNode*Kthnode(ListNode* temp,int k)
{
    k-=1;
    while(temp && k>0)
    {
        k--;
        temp=temp->next;
    }
    return temp;
}
ListNode* reverse(ListNode* head)
{
    ListNode*curr=head;
    ListNode*prev=NULL;
    while(curr!=NULL)
    {
        ListNode* nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    return prev;
} 
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1)
        return head;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        dummy->next = head;
        ListNode* temp = head;
        ListNode* prelast = dummy;
        while(temp)
        {
            ListNode* kthnode=Kthnode(temp,k);
            if(kthnode==NULL) break;
            ListNode* nextnode=kthnode->next;
           kthnode->next=NULL;

           ListNode* reversehead=reverse(temp);
           prelast->next = reversehead;
           
           prelast=temp;
           temp=nextnode;
           prelast->next = temp;
           
        }
        return dummy->next;
    }
};