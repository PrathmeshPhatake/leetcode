/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str="";
        if(root==NULL) return str;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL)
            {
                str.append("#,");
            }
            else
            {
                str.append(to_string(temp->val)+",");
                q.push(temp->left);
                q.push(temp->right);
            }
            
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string str;
        if(data.empty()) return NULL;
        queue<TreeNode*>q;
        getline(ss,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty())
        {
            TreeNode* root=q.front();
            q.pop();
            
            //for right 
            getline(ss,str,',');
            if(str=="#")
            {
                root->left=NULL;
            }
            else
            {
                TreeNode*temp=new TreeNode(stoi(str));
                q.push(temp);
                root->left=temp;
            }
            //for right 
            getline(ss,str,',');
            if(str=="#")
            {
                root->right=NULL;
            }
            else
            {
                TreeNode*temp=new TreeNode(stoi(str));
                q.push(temp);
                root->right=temp;
            }
        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;