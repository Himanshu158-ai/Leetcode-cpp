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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;

        ListNode* t1 = head;
        ListNode* p1 = NULL;
        int pos = 1;
        while(pos<left){
            p1 = t1;
            t1 = t1->next;
            pos++;
        }

        ListNode* t2 = t1;
        ListNode* nxt = NULL;
        ListNode* p2 = NULL;
        while(pos<=right){
            nxt = t2->next;
            t2->next = p2;
            p2 = t2;
            t2 = nxt;
            pos++;
        }

        // if(!p1 && !t2) return p2;
        
        if(!p1){
            t1->next = t2;
            return p2;
        }
        p1->next = p2;
        t1->next = t2;
        return head;
    }
};