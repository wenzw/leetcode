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
    int max;
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return 0;
        max = -0x7FFFFFFF;
        _maxPathSum(root);
        return max;
    }
    
    int _maxPathSum(TreeNode* n) {
        if (n == NULL) return 0;
        int l = _maxPathSum(n -> left);
        l = l > 0 ? l : 0;
        int r = _maxPathSum(n -> right);
        r = r > 0 ? r : 0;
        int curmax = l + n -> val + r;
        if (curmax > max) {
            max = curmax;
        }
        int res = l > r ? l : r;
        return res + n -> val;
    }
};
