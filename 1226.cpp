class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (!pListHead || k <= 0) return nullptr;
        int n = 0;
        ListNode *cur = pListHead;
        while (cur) {
            cur = cur->next;
            ++n;
        }
        if (n < k) return nullptr;
        n -= k;
        while (n--) {
            pListHead = pListHead->next;
        }
        return pListHead;
 
    }
};
