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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* temp = head;
        while(temp){
            sz++;
            temp = temp->next;
        }

        if(n == sz){
            return head->next;
        }

        int act_sz = sz-n;

        temp =  head;
        while(temp){
            act_sz--;
            if(act_sz==0){
                ListNode* nxt = temp->next;
                temp->next = nxt->next;
                nxt->next = NULL;
                break;
            }

            temp = temp->next;
        }

        return head;
    }
};