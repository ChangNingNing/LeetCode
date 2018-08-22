/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        for (ListNode* cur=head; cur!=NULL; cur=cur->next)
            n++;
        
        ListNode *ans = new ListNode(-1), *ans_cur = ans;
        ListNode *pre=NULL, *cur=head, *tmp=NULL;
        int count = 0;
        while (cur != NULL){
            pre = cur, cur = cur->next;
            count++;

            if (n % k != 0 && count > n / k * k){
                ans_cur->next = pre;
                ans_cur = ans_cur->next;
                continue;
            }
            pre->next = tmp;
            tmp = pre;
            
            if (count % k == 0){
                ans_cur->next = tmp;
                while (ans_cur->next != NULL)
                    ans_cur = ans_cur->next;
                tmp = NULL;
            }
        }
        return ans->next;
    }
};
