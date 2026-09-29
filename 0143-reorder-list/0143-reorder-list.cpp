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
    void reorderList(ListNode* head) {
        
        ListNode* temp = head;
        ListNode* p1 = head;
        ListNode* p2 = head;

        int count = 0;
        while(temp -> next != NULL){
            temp = temp -> next;
            count++;
        }
        int middle =  count/2;

        for(int i = 0; i <= middle; i++){
            p2 = p2 -> next;
        }

        //Reversing from p2 to end
        ListNode* prev = NULL;
        ListNode* curr = p2;
        while(curr != NULL){
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* p1next;
        ListNode* prevNext;
        for(int i = 0; i < middle; i++){
            p1next = p1 -> next;
            p1 -> next = prev;
            p1 = p1next;
            prevNext = prev -> next;
            prev -> next = p1;
            prev = prevNext;
        }

        p1 -> next = prev;

    }
};
