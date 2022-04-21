class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur=head,*pre=NULL;
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
