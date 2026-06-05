class Solution {
public:
    int func(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftheight = func(root->left);
        if (leftheight == -1) {
            return -1;
        }
        int rightheight = func(root->right);
        if (rightheight == -1) {
            return -1;
        }
        if (abs(leftheight - rightheight) > 1) {
            return -1;
        }
        return max(leftheight, rightheight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return func(root)!=-1;
    }
};