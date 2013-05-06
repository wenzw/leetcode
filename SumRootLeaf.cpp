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
    int sum;
public:
    int sumNumbers(TreeNode *root) {
        if (root == NULL) return 0;
        sum = 0;
        sumNumber(root, 0);
        return sum;
    }
    
    void sumNumber(TreeNode* node, int cur) {
        int v = cur * 10 + node -> val;
        if (node -> left == NULL && node -> right == NULL) {
            sum += v;
            return;
        }
        if (node -> left != NULL) {
            sumNumber(node -> left, v);
        }
        if (node -> right != NULL) {
            sumNumber(node -> right, v);
        }
    }
};
