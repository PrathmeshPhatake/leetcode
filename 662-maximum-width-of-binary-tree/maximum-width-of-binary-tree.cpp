class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            long long left = q.front().second; 
            long long right = q.back().second; 
            maxWidth = max(maxWidth, (int)(right - left + 1));

            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();

                long long normalizedIndex = index - left;

                if (node->left) {
                    q.push({node->left, 2 * normalizedIndex});
                }
                if (node->right) {
                    q.push({node->right, 2 * normalizedIndex + 1});
                }
            }
        }

        return maxWidth;
    }
};
