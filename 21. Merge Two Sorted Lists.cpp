/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(),*cur = res;
        ListNode *p = l1,*q = l2;
        while (p && q){
            if (p->val < q->val){
                cur->next = p;
                p = p->next;
            } 
            else{
                cur->next = q;
                q = q->next;
            }
            cur = cur->next;
        }
        if (p) cur->next = p;
        if (q) cur->next = q;
        return res->next;
    }
};