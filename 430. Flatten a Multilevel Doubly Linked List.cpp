/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    vector<Node*> res;
    Node* flatten(Node* head) {
        traverse(head);
        int n = res.size();
        for (int i=0;i<n;i++){
            if (i+1 < n) res[i]->next = res[i+1];
            if (i > 0) res[i]->prev = res[i-1];
            res[i]->child = NULL;
        }
        return head;
    }
    void traverse(Node* head){
        if (head == NULL) return;
        res.push_back(head);
        traverse(head->child);
        traverse(head->next);
    }
};