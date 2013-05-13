#include <iostream>

using namespace std;

struct Node {
    char val;
    Node* next;
    Node(char v, Node* n):val(v),next(n){}
};

Node* fb_change(Node* head) {
    if (head == NULL) return NULL;
    int cnt = 0;
    Node* p = head;
    while (p != NULL) {
        cnt++;
        p = p -> next;
    }
    int mid = cnt / 2;
    p = head;
    for (int i = 0; i < mid; i++) {
        p = p -> next;
    }
    Node* pmid = p;
    if (pmid == NULL) return head;
    Node* pn1 = p -> next;
    if (pn1 == NULL) return head;
    Node* pn2 = pn1 -> next;
    while (pn1 != NULL) {
        pn1 -> next = p;
        p = pn1;
        pn1 = pn2;
        if (pn1 != NULL) {
            pn2 = pn1 -> next;
        }
    }
    Node* ptail = p;

    p = head;
    Node* pt = ptail;
    while (pt != pmid) {
        Node* ptmp = pt -> next;
        pt -> next = p -> next;
        p -> next = pt;
        p = pt -> next;
        pt = ptmp;
    }
    pmid -> next = NULL;
    return head;
}
