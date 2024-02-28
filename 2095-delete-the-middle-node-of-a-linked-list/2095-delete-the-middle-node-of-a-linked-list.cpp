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
    //first find len then get middle node index 
    //then taraverse list 
public:
int getlen(ListNode* head)
{
    int len=0;
    while(head!=NULL)
    {
        head=head->next;
        len++;
    }
    return len;
}
    ListNode* deleteMiddle(ListNode* head) {
      int len=getlen(head);
      int ans=len/2;
      if(head==NULL ||head->next==NULL)
      {
          return NULL;
      }
      int cnt=0;
      ListNode*pre=NULL;
      ListNode* curr=head;
      while(cnt<ans)
      {
         pre=curr;
         curr=curr->next;
         cnt++;
      }
      pre-> next = curr->next;
      
      delete curr;
      return head;
       
    }
};