/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL),
             right(NULL), next(NULL) {}

    Node(int _val) : val(_val),
                     left(NULL),
                     right(NULL),
                     next(NULL) {}

    Node(int _val, Node* _left,
         Node* _right, Node* _next)
        : val(_val),
          left(_left),
          right(_right),
          next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        if (!root) {
            return nullptr;
        }

        Node* current = root;

        while (current) {

            Node dummy(0);
            Node* tail = &dummy;

            // Traverse current level
            while (current) {

                if (current->left) {

                    tail->next = current->left;
                    tail = tail->next;
                }

                if (current->right) {

                    tail->next = current->right;
                    tail = tail->next;
                }

                current = current->next;
            }

            // Move to next level
            current = dummy.next;
        }

        return root;
    }
};