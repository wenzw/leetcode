/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>
class Solution {
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* pre = NULL;
        while (!s.empty()) {
            TreeNode* p = s.top();
            s.pop();
            if (p -> right != NULL) {
                s.push(p -> right);
            }
            if (p -> left != NULL) {
                s.push(p -> left);
            }
            if (pre == NULL) {
                pre = p;
            } else {
                pre -> left = NULL;
                pre -> right = p;
                pre = p;
            }
        }
    }
};
