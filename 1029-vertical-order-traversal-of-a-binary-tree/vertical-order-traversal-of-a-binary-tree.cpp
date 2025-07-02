/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void func(TreeNode*root,int i,int h,map<int,vector<pair<int,int>>>&mp)
{
    if(root==NULL)
    {
        return ;
    }
    mp[i].push_back({h,root->val});
    func(root->left,i-1,h+1,mp);
    func(root->right,i+1,h+1,mp);
}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>mp;
        func(root,0,0,mp);
        vector<vector<int>>ans;
        for(auto it:mp)
        {
            sort(it.second.begin(),it.second.end());
            vector<int>temp;
            for(auto num:it.second)
            {
                temp.push_back(num.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};