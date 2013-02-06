/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return 0;
        return _minDepth(root);
    }
    
    int _minDepth(TreeNode* root) {
        if (root -> left == NULL && root -> right == NULL) {
            return 1;
        }
        if (root -> left == NULL && root -> right != NULL) {
            return 1 + _minDepth(root -> right);
        }
        if (root -> left != NULL && root -> right == NULL) {
            return 1 + _minDepth(root -> left);
        }
        return 1 + min(_minDepth(root -> left), _minDepth(root -> right));
    }
};
