/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)
        {
            return { };

        }
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>ans;
        q.push(NULL);
        vector<int>temp;
        while(!q.empty())
        {
            Node*node=q.front();
            q.pop();
            if(node==NULL)
            {
                ans.push_back(temp);
                temp.clear();
                if(!q.empty())
                {
                    q.push(NULL);
                }

            }
            else
            {
                temp.push_back(node->val);
                for(auto it:node->children)
                {
                    q.push(it);
                }
            }
        }
        return ans;
    }
};