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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k);
        int n = 0,mod = 0,div = 0;
        ListNode* p = head;
        while (p){
            n++;
            p = p->next;
        }
        div = n / k;
        mod = n % k;
        p = head;
        for (int i=0;i<k && p != nullptr;i++){
            res[i] = p;
            int cursize = div + (mod-- > 0 ? 1 : 0);
            for (int j=0;j<cursize-1;j++){
                p = p->next;
            }
            ListNode* next = p->next;
            p->next = nullptr;
            p = next;
        }
        return res;
    }
};