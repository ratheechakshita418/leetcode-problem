class Solution {
private:
    int count = 0;
    int result = -1;
    void inorder(TreeNode* node, int k) {
        if (node == nullptr || count >= k) return;
        inorder(node->left, k);
        count++;
        if (count == k) {
            result = node->val;
            return;
        }
        inorder(node->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        inorder(root, k);
        return result;
    }
};