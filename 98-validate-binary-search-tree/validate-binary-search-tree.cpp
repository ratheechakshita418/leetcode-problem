class Solution {
private:
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        if (node == nullptr) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;
        return validate(node->left, minVal, node->val) && 
               validate(node->right, node->val, maxVal);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};