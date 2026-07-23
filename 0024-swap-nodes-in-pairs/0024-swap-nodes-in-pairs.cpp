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
    ListNode* swapPairs(ListNode* head) {
        if(!head || head->next==NULL) return head;

        ListNode* curr = head;
        head = head->next;
        ListNode* pr = NULL;
        ListNode* currNxt1 = NULL;
        ListNode* currNxt2 = NULL;
        while(curr && curr->next!=NULL ){
            currNxt1 = curr->next;
            currNxt2 = curr->next->next;
            if(pr) pr->next = currNxt1;
            currNxt1->next = curr;
            curr->next = currNxt2;
            pr = curr;
            curr = curr->next;
        }
        return head;

    }
};