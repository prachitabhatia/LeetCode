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
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 0;
        if(head == NULL){
            return head;
        }
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp -> next;
            count++;
        }
        ListNode* p1 = head;

        k = k % count; //actual number of rotation is (k % numberOfNodes)

        if(k == 0){
            return head;
        }

        for(int i = 1; i <= count - k - 1; i++){
            p1 = p1 -> next;
        }
        ListNode* prev = p1;
        ListNode* newHead;
        newHead = prev -> next;

        p1 = p1 -> next;
        prev -> next = NULL;

        for(int i = 1; i < k; i++ ){
            p1 = p1-> next;
        }
        p1 -> next = head;
        head = newHead;
        return head;
    }
};