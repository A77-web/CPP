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
    vector<int> reversePrint(ListNode* head) {
        stack<int> st;
        while(head)
        {
            st.push(head->val);
            head=head->next;
        }
        vector<int> v;
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        return v;
    }
};
