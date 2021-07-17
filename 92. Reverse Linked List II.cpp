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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ans =new ListNode(0),*cur = head;
        ans->next = head;
        ListNode* pre = ans;
        for (int i=1;i<left;i++) pre = pre->next;
        cur = pre->next;
        for (int i=left;i<right;i++){
            ListNode* nex = cur->next;
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
        }
        return ans->next;
    }
};