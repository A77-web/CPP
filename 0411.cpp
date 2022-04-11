class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        stack<int> st;
        ListNode* cur=head;
        while(cur!=NULL)
        {
            st.push(cur->val);
            cur=cur->next;
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
