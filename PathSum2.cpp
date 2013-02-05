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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > vvi;
        if (root == NULL) return vvi;
        vector<TreeNode*> v;
        v.push_back(root);
        int cursum = root -> val;
        while (root -> left != NULL) {
            v.push_back(root -> left);
            cursum += root -> left -> val;
            root = root -> left;
        }
        while (!v.empty()) {
            TreeNode* p = v.back();
            if (p -> right == NULL) {
                // is leaf
                if (cursum == sum) {
                    vvi.push_back(buildResult(v));
                }
                v.pop_back();
            } else {
                while (p -> 
            }
        }
    }
    vector<int> buildResult(vector<TreeNode*> v) {
        vector<int> v;
        vector<TreeNode*>::iterator it = v.begin();
        for (; it != v.end(); it++) {
            v.push_back(*it -> val);
        }
        return v;
    }
};
