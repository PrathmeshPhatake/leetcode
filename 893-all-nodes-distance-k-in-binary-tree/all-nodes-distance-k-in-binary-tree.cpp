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
 void parentmap(unordered_map<TreeNode*,TreeNode*>&mp,TreeNode*root)
 {
    if(root==NULL) return ;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        if(node->left)
        {
            q.push(node->left);
            mp[node->left]=node;
        }
        if(node->right)
        {
            q.push(node->right);
            mp[node->right]=node;
        }
    }
 }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        parentmap(mp,root);
        queue<TreeNode*>q;
        q.push(target);
        unordered_set<TreeNode*>st;
        st.insert(target);
        int dist=0;
        while(!q.empty() && dist<k)
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !st.count(node->left))
                {
                    st.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && !st.count(node->right))
                {
                    st.insert(node->right);
                    q.push(node->right);
                }
                if(mp.find(node)!=mp.end() && !st.count(mp[node]))
                {
                    st.insert(mp[node]);
                    q.push(mp[node]);
                }
            }
            dist++;
        }
        vector<int>ans;
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};