// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
//         int rs=0;
//         int re=m-1;
//         int cs=0;
//         int ce=n-1;
//         vector<vector<int>>ans(m,vector<int>(n,-1));

//         ListNode*temp=head;
//         while(temp!=NULL)
//         {
           
            
//                 for(int i=cs;i<=ce && temp!=NULL;i++)
//                 {
//                     ans[rs][i]=temp->val;
//                     temp=temp->next;
//                 }
//                 rs++;
            
            
//                 for(int i=rs;i<=re && temp!=NULL;i++)
//                 {
//                     ans[i][ce]=temp->val;
//                     temp=temp->next;
//                 }
//                 ce--;
            
            
//                 for(int i=ce;i>=cs && temp!=NULL;i--)
//                 {
//                     ans[re][i]=temp->val;
//                     temp=temp->next;
//                 }
//                 re--;
            
            
//                 for(int i=re;i>=rs && temp!=NULL;i--)
//                 {
//                     ans[i][cs]=temp->val;
//                     temp=temp->next;
//                 }
//                 cs++;
            
//         }
//         return ans;
//     }
// };
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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int rs=0;
        int re=m-1;
        int cs=0;
        int ce=n-1;
        vector<vector<int>>ans(m,vector<int>(n,-1));

        ListNode*temp=head;
        while(temp!=NULL)
        {
            if(rs<=re)
            {
                for(int i=cs;i<=ce && temp!=NULL;i++)
                {
                    ans[rs][i]=temp->val;
                    temp=temp->next;
                }
                rs++;
            }
            if(ce>=cs)
            {
                for(int i=rs;i<=re && temp!=NULL;i++)
                {
                    ans[i][ce]=temp->val;
                    temp=temp->next;
                }
                ce--;
            }
            if(re>=rs)
            {
                for(int i=ce;i>=cs && temp!=NULL;i--)
                {
                    ans[re][i]=temp->val;
                    temp=temp->next;
                }
                re--;
            }
            if(cs<=ce)
            {
                for(int i=re;i>=rs && temp!=NULL;i--)
                {
                    ans[i][cs]=temp->val;
                    temp=temp->next;
                }
                cs++;
            }
        }
        return ans;
    }
};