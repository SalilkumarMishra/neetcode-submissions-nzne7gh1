class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Check if there are at least k nodes
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == nullptr) return head; // not enough nodes
            temp = temp->next;
        }

        // Step 2: Reverse first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        int count = 0;
        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 3: Recursive call for remaining list
        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        // prev is new head of this group
        return prev;
    }
};