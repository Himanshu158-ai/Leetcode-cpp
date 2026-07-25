/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        // Find length
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Handle k > length
        k %= count;
        if (k == 0)
            return head;

        int traverse = count - k;

        ListNode* prv = nullptr;
        ListNode* curr = head;

        while (traverse--) {
            prv = curr;
            curr = curr->next;
        }

        // Find last node
        temp = curr;
        while (temp->next) {
            temp = temp->next;
        }

        // Rotate
        temp->next = head;
        prv->next = nullptr;

        return curr;
    }
};