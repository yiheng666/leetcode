class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* p = l1,*q = l2,*t = res;
        int carry = 0;
        while (p || q || carry){
            int val = carry;
            if (p){
                val += p->val;
                p = p->next;
            }
            if (q){
                val += q->val;
                q = q->next;
            }
            carry = val / 10;
            val = val % 10;
            t->next = new ListNode(val);
            t = t->next;
        }
        return res->next;
    }
};