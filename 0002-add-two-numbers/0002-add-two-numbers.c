/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
        struct ListNode *temp1, *temp2, *temp3, *newNode;
        struct ListNode* l3; //header to third pointer.

        int sum;
        int carry = 0;
        int val1,val2,val3;
        temp1 = l1; temp2 = l2; temp3 = l3;

        while(temp1 != NULL || temp2 != NULL){
            val1 = 0;
            val2 = 0;
            if(temp1 != NULL){
                val1 = temp1 -> val;
                temp1 = temp1 -> next;
            }
            if(temp2 != NULL){
                val2 = temp2 -> val;
                temp2 = temp2 ->next;
            }
            sum = val1 + val2 + carry;
            carry = sum/10;
            val3 = sum % 10;

            newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode -> val = val3;
            newNode -> next = NULL;

            if(l3 == NULL){
                l3 = newNode;
                temp3 = newNode;
            }
            else{
                temp3 -> next = newNode;
                temp3 = temp3 -> next;
            }
            
        }
        if(carry != 0){
            newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode -> val = carry;
            newNode -> next = NULL;
            temp3 -> next = newNode;
        }
        return l3;
}