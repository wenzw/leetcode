/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#include <queue>
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;
        queue<TreeLinkNode*> q;
        bool flag = false;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            TreeLinkNode* p = q.front();
            q.pop();
            if (p == NULL)
            {
                if (!flag)
                    q.push(NULL);
                continue;
            }
            p -> next = q.front();
            if (p -> left == NULL)
            {
                flag = true;
            }
            else
            {
                q.push(p -> left);
                q.push(p -> right);
            }
        }
    }
};
