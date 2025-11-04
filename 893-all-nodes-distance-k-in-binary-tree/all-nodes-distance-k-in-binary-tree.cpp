/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void parent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&mp)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        
            TreeNode*node=q.front();
            q.pop();
            if(node->left) q.push(node->left); mp[node->left]=(node);
            if(node->right) q.push(node->right); mp[node->right]=(node);
            
    }
    
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        parent(root,mp);
        queue<TreeNode*>q;
        unordered_set<TreeNode*>seen;
        // node dist
        q.push(target);
        seen.insert(target);
        int dist=0;
        while(!q.empty() && dist<k){
            int size=q.size();
            while(size--){
                TreeNode*node=q.front();
                q.pop();
                if(node->left && seen.insert(node->left).second) q.push(node->left); 
                if(node->right && seen.insert(node->right).second) q.push(node->right); 
                if(mp.count(node) && seen.insert(mp[node]).second) q.push(mp[node]);
            }
            dist++;
        }
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;


    }
};