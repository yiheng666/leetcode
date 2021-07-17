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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ans = new ListNode(0),*pre = head,*cur = head;
        ans->next = head;
        int length = 0;
        while (pre){
            length++;
            pre = pre->next;
        }
        pre = ans;
        for (int i=0;i<length/k;i++){
            for (int j=0;j<k-1;j++){
                ListNode *nex = cur->next;
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
            }
            pre = cur;
            cur = pre->next;
        }
        return ans->next;
    }
};