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
    
    void recursiveReverseMethod1(ListNode** head_ref)
    {
        ListNode* first;
        ListNode* rest;
      /* empty list */
        if (*head_ref == NULL)
          return;   
      /* suppose first = {1, 2, 3}, rest = {2, 3} */
         first = *head_ref;  
        rest  = first->next;
        /* List has only one node */
        if (rest == NULL)
            return;   
        /* reverse the rest list and put the first element at the end */
        recursiveReverseMethod1(&rest);
        first->next->next  = first;  
        /* tricky step -- see the diagram */
        first->next  = NULL;          
        /* fix the head pointer */
        *head_ref = rest;              
    }
    
    void reverseListRecursiveMethod2(ListNode *curr, ListNode *prev, ListNode **head)
    {      
        /* If last node mark it head*/
        if (!curr->next)
        {
            *head = curr;
            /* Update next to prev node */
            curr->next = prev;
            return ;
        }
        /* Save curr->next node for recursive call */
        ListNode *next = curr->next;
        /* and update next ..*/
        curr->next = prev;
        reverseListRecursiveMethod2(next, curr, head);
    }
    
    ListNode* reverseListIterativeMethod(ListNode* head){
        ListNode *currNode = head;
		ListNode *nextNode = NULL;
		ListNode *prevNode = NULL;

		while(currNode!=NULL){
			nextNode = currNode->next;
			currNode->next = prevNode;
			prevNode = currNode;
			currNode = nextNode;
		}
		head = prevNode;
        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        //recursiveReverseMethod1(&head);
        //reverseListRecursiveMethod2(head, NULL,&head);
        head = reverseListIterativeMethod(head);
        return head;
    }
};