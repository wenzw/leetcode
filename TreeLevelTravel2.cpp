 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > vvi;
        if (root == NULL) return vvi;
        queue<TreeNode*> q;
        vector<int> v;
        vector<int>* pv = &v;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* p = q.front();
            q.pop();
            if (p == NULL) {
                if (!v.empty()) {
                    vvi.insert(vvi.begin(), v);
                    v.clear();
                }
            } else {
                v.push_back(p -> val);
                if (p -> left != NULL) {
                    q.push(p -> left);
                }
                if (p -> right != NULL) {
                    q.push(p -> right);
                }
                if (q.front() == NULL) {
                    q.push(NULL);
                }
            }
        }
        return vvi;
    }
};
