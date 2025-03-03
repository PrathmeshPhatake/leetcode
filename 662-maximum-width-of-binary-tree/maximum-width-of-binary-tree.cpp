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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        long long  maxi=-1;
        while(!q.empty()){
            int size=q.size();
            long long  leftmost=q.front().second;
            long long  rightmost=q.back().second;
            maxi=max(maxi,rightmost-leftmost+1);
            for(int i=0;i<size;i++)
            {
                auto [node,val]=q.front();
                q.pop();
                long long newVal = val - leftmost;
               if(node->left) q.push({node->left,newVal*2+1});
               if(node->right) q.push({node->right,newVal*2+2});

            }
        }
        return maxi;
    }
};