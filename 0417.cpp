class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* xn=new ListNode(0);
        ListNode* p=xn,*p1=list1,*p2=list2;
        while(p1!=NULL&&p2!=NULL)
        {
            if(p1->val<p2->val)
            {
                p->next=p1;
                p1=p1->next;
            }
            else
            {
                p->next=p2;
                p2=p2->next;
            }
            p=p->next;
        }
        if(p1==NULL)
        {
            p->next=p2;
        }
         if(p2==NULL)
        {
            p->next=p1;
        }
        return xn->next;

    }
};
