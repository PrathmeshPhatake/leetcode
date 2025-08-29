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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<vector<int>>dp;
        while(head){
            vector<int>temp;
            for(int i=0;i<k && head;i++)
            {
                temp.push_back(head->val);
                head=head->next;
            }
            // sort(temp.begin(),temp.end());
            // reverse(temp.begin(),temp.end());
            dp.push_back(temp);
        }
         ListNode*ans=new ListNode(NULL);
          ListNode*anspoint=ans;
        for(auto it:dp)
        {
            if(it.size()==k)
            {
            // sort(it.begin(),it.end());
            reverse(it.begin(),it.end());
            }
            for(auto x:it){
                ListNode*temp=new ListNode(x);
                anspoint->next=temp;
                anspoint=anspoint->next;
            }
        }
        return ans->next;
    }
};