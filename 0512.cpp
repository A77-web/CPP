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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;
        ListNode *p=headA;
        while(p!=nullptr)
        {
            st.insert(p);
            p=p->next;
        }
        p=headB;
        while(p!=nullptr)
        {
            if(st.count(p))
            {
                return p;
            }
            p=p->next;
        }
        return nullptr;
    }
};
