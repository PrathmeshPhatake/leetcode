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
void func(TreeNode*root,int l,map<int,int>&mp)
{
    if(root==NULL)return;
    if(mp.find(l)==mp.end())
    {
        mp[l]={root->val};
    }
    func(root->right,l+1,mp);
    func(root->left,l+1,mp);
}
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>mp;
        vector<int>ans;
        func(root,0,mp);
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};