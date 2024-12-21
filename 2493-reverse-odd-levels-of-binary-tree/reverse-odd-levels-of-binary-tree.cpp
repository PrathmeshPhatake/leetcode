/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> currentlevel;
            for (int i = 0; i < size; i++) {
                // push node of current level;
                TreeNode* temp = q.front();
                q.pop();
                currentlevel.push_back(temp);

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }

            if (level % 2 == 1) {
                int left = 0;
                int right = currentlevel.size() - 1;
                while (left < right) {
                    swap(currentlevel[left]->val, currentlevel[right]->val);
                    left++;
                    right--;
                }
            }
            level++;
        }
        return root;
    }
};