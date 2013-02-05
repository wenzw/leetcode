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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return false;
        return _hasPathSum(root, sum);
    }
    
    bool _hasPathSum(TreeNode* p, int sum) {
        if (p -> left == NULL && p -> right == NULL) return p -> val == sum ? true : false;
        bool l = false;
        if (p -> left != NULL) {
            l = _hasPathSum(p -> left, sum - p -> val);
        }
        if (l) return true;
        bool r = false;
        if (p -> right != NULL) {
            r = _hasPathSum(p -> right, sum - p -> val);
        }
        if (r) return true;
        return false;
    }
};
