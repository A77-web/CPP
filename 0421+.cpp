class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val==val)
        {
            head=head->next;
            return head;
        }
        ListNode* p=head,*q=head->next;
        while(q!=NULL&&q->val!=val)
        {
            p=q;
            q=q->next;
        }    
        if(q->val==val)
            p->next=q->next;
        return head;
    }
};
