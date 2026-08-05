/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev;
    struct ListNode *current;

    if(head == NULL || head -> next == NULL){
        return head;
    }
    prev = head;
    head = head -> next;
    current = head;
    prev -> next = NULL; //setting last of reversed list to NULL.

    while(head != NULL){
        head = head -> next;
        current -> next = prev;
        prev = current;
        current = head;
    }
    head = prev; //setting last element as head of reversed list.
    return head;
}