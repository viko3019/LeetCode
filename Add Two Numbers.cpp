/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverseList(ListNode* head){
        if( head== NULL || head->next == NULL){
            return head;
        }
        ListNode*prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *prev = NULL;
        int carry = 0;
        while (l1 || l2) {
            int v1 = l1? l1->val: 0;
            int v2 = l2? l2->val: 0;
            int tmp = v1 + v2 + carry;
            carry = tmp / 10;
            int val = tmp % 10;
            ListNode* cur = new ListNode(val);
            if (!head) head = cur;
            if (prev) prev->next = cur;
            prev = cur;
            l1 = l1? l1->next: NULL;
            l2 = l2? l2->next: NULL;
        }
        if (carry > 0) {
            ListNode* l = new ListNode(carry);
            prev->next = l;
        }
        return head;
    }
};