class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        ListNode* dummy = new ListNode(0);

        ListNode* curr = head;

        while (curr != NULL) {

            ListNode* nextNode = curr->next;

            ListNode* prev = dummy;

            // Find correct position
            while (prev->next != NULL &&
                   prev->next->val < curr->val) {

                prev = prev->next;
            }

            // Insert node
            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode;
        }

        return dummy->next;
    }
};