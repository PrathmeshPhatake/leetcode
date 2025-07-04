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
void findparent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parent)
{
    // node parent
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode*node=q.front();
        q.pop();
        if(node->left) q.push(node->left); parent[node->left]=node;
        if(node->right) q.push(node->right); parent[node->right]=node;
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       // used bfs for 
       unordered_map<TreeNode*,TreeNode*>parent;
       findparent(root,parent);
       unordered_set<TreeNode*>seen;
       queue<TreeNode*>q;
       seen.insert(target);
       q.push(target);
       int dist=0;
       while(!q.empty()&&dist<k)
       {
           int len=q.size();
           while(len--){
            TreeNode*node=q.front();
            q.pop();
            // left ,right , parent
            if(node->left && seen.insert(node->left).second) q.push(node->left);
            if(node->right && seen.insert(node->right).second) q.push(node->right);
            if(parent.count(node) && seen.insert(parent[node]).second) q.push(parent[node]);
           }
           dist++;
       } 
       vector<int>ans;
       while(!q.empty())
       {
        TreeNode*node=q.front();
        q.pop();
        ans.push_back(node->val);

       }return ans;
    }
};