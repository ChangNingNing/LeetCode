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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(-1);
        int carry = 0;
        for (ListNode *cur1=l1, *cur2=l2, *_ans = ans; cur1!=NULL || cur2!=NULL || carry!=0;){
            if (cur1 == NULL && cur2 == NULL)
                _ans->next = new ListNode(myAdd(0, 0, carry));
            else if (cur1 == NULL)
                _ans->next = new ListNode(myAdd(0, cur2->val, carry)), cur2 = cur2->next;
            else if (cur2 == NULL)
                _ans->next = new ListNode(myAdd(cur1->val, 0, carry)), cur1 = cur1->next;
            else {
                _ans->next = new ListNode(myAdd(cur1->val, cur2->val, carry));
                cur1 = cur1->next, cur2 = cur2->next;
            }
            _ans = _ans->next;
        }
        return ans->next;
    }
private:
    int myAdd(int x, int y, int& c){
        int z = (x + y + c) % 10;
        c = (x + y + c) / 10;
        return z;
    }
};
