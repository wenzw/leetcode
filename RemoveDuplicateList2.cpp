/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return NULL;
        ListNode* r = NULL;
        ListNode* rt = NULL;
        ListNode* h = head;
        ListNode* t = head;
        while (t != NULL) {
            if (t -> val == h -> val) {
                t = t -> next;
                continue;
            }
            if (h -> next == t) {
                if (r == NULL) {
                    r = h;
                    rt = h;
                } else {
                    rt -> next = h;
                    rt = h;
                }
                h = t;
            } else {
                remove(h, t);
                h = t;
            }
        }
        if (h -> next != NULL) {
            remove(h, NULL);
            if (r == NULL) {
                return r;
            } else {
                rt -> next = NULL;
            }
        } else {
            if (r == NULL) {
                r = h;
                rt = h;
            } else {
                rt -> next = h;
                rt = h;
            }
        }
        return r;
    }

    ListNode* remove(ListNode* from, ListNode* to) {
        while (from != to) {
            ListNode* tmp = from -> next;
            delete from;
            from = tmp;
        }
        return to;
    }
};
