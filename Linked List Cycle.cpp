/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
   Methode 1 - O(n^2) using two loops
   Methode 2 - O(NlogN) with extra space O(N) - using map
   Method 3 - O(NlogN) - sorting
   Method 4 - O(N)  using slow and fast pointer
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(slow != NULL && fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow && fast && slow->val == fast->val){
            return true;
            }
        }
        return false;
    }
};