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
 //1
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = new ListNode(0),*cur = head;
        ans->next = head;
        ListNode* pre = ans;
		//cur==NULL，即链表为空不做处理
		//cur->next==NULL，反转结束
        while (cur && cur->next){
            ListNode* nex = cur->next;
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
        }
        return ans->next;
    }
};
 //2
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=nullptr,*cur = head;
        while (cur){
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};