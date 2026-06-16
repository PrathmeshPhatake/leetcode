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
void func(map<int,vector<pair<int,int>>>&mp,int v,int h,TreeNode*root)
{
    if(root==NULL)
    {
        return;
    }
    mp[h].push_back({v,root->val});
    func(mp,v-1,h+1,root->right);
    func(mp,v+1,h+1,root->left);
}
    vector<int> rightSideView(TreeNode* root) {
        map<int,vector<pair<int,int>>>mp;
        func(mp,0,0,root);
        vector<int>ans;
        for(auto it:mp)
        {
            ans.push_back(it.second[0].second);
        }
        return ans;
    }
};