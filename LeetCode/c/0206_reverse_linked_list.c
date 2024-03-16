/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* current = head;
    struct ListNode *prev = NULL, *after = NULL;
    while (current != NULL) 
    {
        after = current->next;
        current->next = prev;
        prev = current;
        current = after;
    }
    head = prev;
    return (head);
}