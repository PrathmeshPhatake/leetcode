class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;  

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);  
        vector<long long> ans;  
        long long temp = 0;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                temp += node->val;

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            } else {
                ans.push_back(temp);
                temp = 0;

                if (!q.empty()) {
                    q.push(NULL);
                }
            }
        }

        sort(ans.begin(), ans.end());

        
        if (k > ans.size()) return -1;
        return ans[ans.size() - k];
    }
};
