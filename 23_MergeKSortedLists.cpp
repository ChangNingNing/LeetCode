/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef pair<int,int> pii;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        set<pii> A;
        vector<ListNode*> ptr(n, NULL);
        int nEnd = 0;
        for (int i=0; i<n; i++){
            if (lists[i]){
                ptr[i] = lists[i];
                A.insert(pii(ptr[i]->val, i));
                ptr[i] = ptr[i]->next;
            }
            else
                nEnd++;
        }
        ListNode *ans = new ListNode(-1);
        ListNode *cur = ans;
        set<pii>::iterator it;
        while (nEnd < n){
            it = A.begin();
            int val = it->first, id = it->second;
            A.erase(it);
            cur->next = new ListNode(val), cur = cur->next;
            if (ptr[id] != NULL){
                A.insert(pii(ptr[id]->val, id));
                ptr[id] = ptr[id]->next;
            }
            else
                nEnd++;
        }
        return ans->next;
    }
};
