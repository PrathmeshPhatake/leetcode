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
  void findParent(unordered_map<TreeNode*,TreeNode*>&parent,TreeNode* root)
  {
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node=q.front();
        q.pop();
        if(node->left)
        {
            parent[node->left]=node;
            q.push(node->left);
        }
        if(node->right)
        {
            parent[node->right]=node;
           q.push(node->right);
        }
    }
  }
  void findnode(unordered_map<TreeNode*,TreeNode*> &parent,TreeNode*target,int k,vector<int> &ans)
  {
    queue<TreeNode*>q;
    unordered_map<TreeNode*,bool>visited;
    q.push(target);
    visited[target]=true;
    int d=0;
    while(!q.empty())
    {
      
        int size=q.size();
        
        if(d++==k) break;
        for(int i=0;i<size;i++)
        {
           TreeNode* node=q.front();
           q.pop();
           if(node->left && !visited[node->left])
           {
            q.push(node->left);
            visited[node->left]=true;
           }
           if(node->right && !visited[node->right])
           {
            q.push(node->right);
            visited[node->right]=true;
           } 
           if(parent[node] && !visited[parent[node]])
           {
            q.push(parent[node]);
            visited[parent[node]] = true;
           }
        }
    }
    while(!q.empty())
    {
        TreeNode* node=q.front();
         q.pop();
        ans.push_back(node->val);
       
    }

  }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode* >parent;
        vector<int>ans;
        findParent(parent,root);
        findnode(parent,target,k,ans);
        return ans;
    }
};