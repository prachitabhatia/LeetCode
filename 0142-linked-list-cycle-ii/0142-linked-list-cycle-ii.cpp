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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast ->next != NULL){
            fast = (fast -> next)-> next;
            slow = slow -> next;
            if(fast == slow){
                slow = head;
                break;
            }
        }

        // if its not cyclic, return null.
        if(fast == NULL || fast -> next == NULL){
            return NULL;
        }

        while(slow != fast){
            fast = fast -> next;
            slow =  slow -> next;
        }
        return slow;
    }
};