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
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        dfs(root,"",ans);
        return ans;

    }
    void dfs(TreeNode* node,string path,string& ans)
    {
        if(!node)
        return;

        
        path+=char('a'+ node->val);
        if(!node->left && !node->right)
        {
            reverse(path.begin(),path.end());
            if(ans.empty() || path < ans)
            {
                ans=path;
            }
            reverse(path.begin(),path.end());
        }
        dfs(node->left,path,ans);
        dfs(node->right,path,ans);
    }
};