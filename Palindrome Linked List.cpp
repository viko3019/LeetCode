/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
 Method1 - by creating an array of its element , time O(N), space O(N)
 Method2 - store the head pointer of reversed half linked list , then match them..O(N), space O(1)
  
 */
class Solution {
public:
    
    void reverseList(ListNode **head) {
        ListNode *prev = NULL, *ptr = *head, *temp;
        while (ptr) {
            temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
        }
        *head = prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }
        ListNode *p1, *p2; // two pointer to struct List Node
        // find mid
        ListNode *mid = NULL;
        p1 = p2 = head;
        while (p2) {
            p2 = p2->next;
            if (p2) p2 = p2->next;
            if (p2) p1 = p1->next;
        }
        mid = p1;
        reverseList(&(mid->next)); // reverse list ahead of MID
        int ans = true;
        p1 = head;
        p2 = mid->next;
        while (ans == 1 && p2) {
            if (p1->val != p2->val) ans = false;
            p1 = p1->next;
            p2 = p2->next;
       }
       reverseList(&(mid->next)); // reset second half of list to original state.
       return ans;
    }
};