/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
  Methode 1 - using map space O(N) and time O(MlogM)  - using un-ordered map we can do this in O(n)
  Method 2 - O(N*M) using two loops
  Method 3 - count the length of both the list suppose c1,c2 now traverse d= abs(c1-c2) in larger list ,then after that start traversing smaller list simulteneously . Time complexity O(n+m) and space complexity is O(1)
*/
class Solution {
public:
    
    int countLength(ListNode* head){
        int len = 0;
        ListNode *temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1 = countLength(headA);
        int c2 = countLength(headB);
        int diff = abs(c1-c2);
        ListNode* intersectingNode = NULL,*temp = NULL;
        if(c1>=c2){
            intersectingNode = headA;
            temp = headB;
        }
        else{
            intersectingNode = headB;
            temp = headA;
        }
        while(diff>0){
            intersectingNode = intersectingNode->next;
            diff = diff-1;
        }
        while(temp != NULL && intersectingNode != NULL){
            if(temp->val == intersectingNode->val){
                return temp;
            }
            else{
                temp = temp->next;
                intersectingNode = intersectingNode->next;
            }
        }
        return temp;
    }
};