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
//get length from this 
//POSITION IS ONE IS NOT EXIST FOR 
int getlength(ListNode* head)
{
    int cnt=0;
    ListNode* temp=head;
    while(temp!= NULL)
    {
        cnt++;
        temp=temp->next;

    }
    return cnt;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
        {
            return NULL;
        }
        int len=getlength( head)-n;
        ListNode*temp=head;

        // if(len==1)
        // {
        //     head=head->next;
        //     delete temp; 
        // }
        
            
        ListNode* prev=NULL;
        ListNode* curr=head;
        //we want to delete  node  at last 
        
        int cnt=0;
        
        while(cnt<len)
        {
           prev=curr;
           curr=curr->next;
           cnt++;
        }
        if(prev==NULL)
        {
            head=head->next;
        }
        else
        {
            prev->next=curr->next;
           delete curr;
        }
               
        return head;
    }   
    
};