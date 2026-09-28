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
    bool isPalindrome(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        int count = 0;
        
        ListNode* temp = head;
        while(temp != NULL){
            temp =  temp -> next;
            count++;
        }

        int middle = count/2;

        for(int i = 1; i <= middle; i++){
            p2 = p2 -> next;
        }

        //reversing from p2 to end
        
        ListNode* prev = NULL;
        ListNode* curr = p2;
        while(curr != NULL){
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        for(int i = 1; i <= middle; i++){
            if(p1 -> val == prev -> val){
                p1 = p1 -> next;
                prev = prev -> next;
            }
            else{
                return false;
            }
        }
        return true;
    }
};