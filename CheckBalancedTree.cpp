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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return true;
        int h = 0;
        return _isBalanced(root, h);
    }
    
    bool _isBalanced(TreeNode* root, int& h) {
        if (root == NULL) {
            h = 0;
            return true;
        }
        int lh;
        bool l = _isBalanced(root -> left, lh);
        int rh;
        bool r = _isBalanced(root -> right, rh);
        h = 1 + max(lh, rh);
        if (!l || !r) {
            return false;
        }
        int dif = lh - rh;
        if (dif <= -2 || dif >= 2) {
            return false;
        }
        return true;
    }
};
