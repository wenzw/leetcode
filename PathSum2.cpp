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
        map<TreeNode*, int> m;
        v.push_back(root);
        m[root] = 0;
        int cursum = root -> val;
        while (!v.empty()) {
            TreeNode* p = v.back();
            if (m[p] == 0) {
                if (p -> left != NULL) {
                    v.push_back(p -> left);
                    cursum += p -> left -> val;
                    m[p -> left] = 0;
                }
                m[p]++;
            } else if (m[p] == 1) {
                if (p -> right != NULL) {
                    v.push_back(p -> right);
                    cursum += p -> right -> val;
                    m[p -> right] = 0;
                } else {
                    // is leaf
                    if (p -> left == NULL && cursum == sum) {
                        vvi.push_back(buildResult(v));
                    }
                }
                m[p]++;
            } else if (m[p] == 2) {
                cursum -= p -> val;
                v.pop_back();
            }
        }
        return vvi;
    }
    vector<int> buildResult(vector<TreeNode*> v) {
        vector<int> vi;
        vector<TreeNode*>::iterator it = v.begin();
        for (; it != v.end(); it++) {
            vi.push_back((*it) -> val);
        }
        return vi;
    }
};
