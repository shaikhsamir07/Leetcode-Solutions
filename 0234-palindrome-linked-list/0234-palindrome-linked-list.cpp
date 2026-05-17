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

    ListNode* reverse(ListNode* head) {

        ListNode* prev = NULL;

        while (head != NULL) {

            ListNode* nextNode = head->next;

            head->next = prev;

            prev = head;
            head = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if (head == NULL ||
            head->next == NULL) {

            return true;
        }

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL &&
               fast->next->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* secondHalf =
            reverse(slow->next);

        ListNode* firstHalf = head;

        // Compare both halves
        while (secondHalf != NULL) {

            if (firstHalf->val !=
                secondHalf->val) {

                return false;
            }

            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};