/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;
        TreeLinkNode* last = root;
        TreeLinkNode* head = NULL;
        TreeLinkNode* pre = NULL;
        TreeLinkNode* cur = NULL;
        while (last != NULL)
        {
            connectNode(last -> left, head, pre, cur);
            connectNode(last -> right, head, pre, cur);
            last = last -> next;
            if (last == NULL)
            {
                last = head;
                head = NULL;
                pre = NULL;
                cur = NULL;
            }
        }
    }
    
    void connectNode(TreeLinkNode* tmp, TreeLinkNode* &head, TreeLinkNode* &pre, TreeLinkNode* &cur)
    {
            if (tmp != NULL)
            {
                if (head == NULL)
                {
                    head = tmp;
                }
                cur = tmp;
                if (pre == NULL)
                {
                    pre = tmp;
                }
                else
                {
                    pre -> next = cur;
                    pre = cur;
                }
            }
    }
};
