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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return _sortedArrayToBST(num, 0, num.size());
    }
    
    TreeNode* _sortedArrayToBST(vector<int>& num, int pos, int len) {
        if (len <= 0) return NULL;
        int mid = pos + len / 2;
        TreeNode* root = new TreeNode(num[mid]);
        root -> left = _sortedArrayToBST(num, pos, mid - pos);
        root -> right = _sortedArrayToBST(num, mid + 1, len - (mid - pos + 1));
        return root;
    }
};
