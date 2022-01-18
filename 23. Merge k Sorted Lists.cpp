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
    struct cmp{
        bool operator() (ListNode* a,ListNode* b){
            //从小到大排列
            return a->val >= b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode();
        ListNode* p = res;
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        int n = lists.size();
        for (int i=0;i<n;i++){
            ListNode* node = lists[i];
            //必须要判断下，不然过不了[[]]。
            //尝试在这里把每一个节点都放进优先队列，然后直接从优先队列里取数据。遇到负数数据会失败，原因不明
            if (node) pq.push(node);
        }
        while (!pq.empty()){
            p->next = pq.top();
            p = p->next;
            pq.pop();
            if (p->next) pq.push(p->next);
        }
        return res->next;
    }
};