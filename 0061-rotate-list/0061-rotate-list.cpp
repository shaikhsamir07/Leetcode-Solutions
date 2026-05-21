/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next)
 *         : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || !head->next || k == 0) {
            return head;
        }

        // Find length and tail
        int length = 1;
        ListNode* tail = head;

        while (tail->next) {

            tail = tail->next;
            length++;
        }

        // Make circular list
        tail->next = head;

        // Effective rotations
        k = k % length;

        int stepsToNewTail = length - k - 1;

        ListNode* newTail = head;

        for (int i = 0;
             i < stepsToNewTail;
             i++) {

            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;

        // Break circle
        newTail->next = nullptr;

        return newHead;
    }
};