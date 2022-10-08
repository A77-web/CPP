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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* cur=head;
        while(cur)
        {
            ListNode* tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;

        }
        return pre;
    }
};
