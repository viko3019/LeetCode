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
    ListNode* algo1(ListNode *head,int n){
        ListNode* first = head;
        ListNode* second = head;
        int i = 0;
        while (second) {
            i++;
            second = second->next;
        }
        int j= 0;
        if(i==n) return head->next;
        while (j < i-n -1) {
            first = first->next;
            j++;
        }
        first->next = first->next->next;
        return head;
    }
    
    ListNode *algo2(ListNode *head,int n){
        ListNode* cur = head, *prev = head;
        while(n-- > 0) {
            cur = cur->next;
        }
        if (cur == NULL) 
            return head->next;
        while (cur->next != NULL) {
            cur = cur->next;
            prev = prev->next;
        }
        prev->next = prev->next->next;
        return head;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       // return algo1(head,n);
        return algo2(head,n);
    }
};