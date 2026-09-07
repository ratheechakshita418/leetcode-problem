class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        // Phase 1: Detect if a cycle exists
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Phase 2: Find the start of the cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Start node of the cycle
            }
        }
        return nullptr; // No cycle found
    }
};