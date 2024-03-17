/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int>Hmap;
        if(head==NULL ||head->next==NULL)
        {
            return false;
        }
        ListNode*temp=head;
        while(temp!=NULL)
        {
            if(Hmap.find(temp)!=Hmap.end())
            {
                return true;
            }
            Hmap[temp]=1;
            temp=temp->next;
        }
        return false;
    }
};