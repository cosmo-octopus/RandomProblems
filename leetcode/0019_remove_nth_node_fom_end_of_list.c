/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode *prev;
    int len = 0;
    for (prev = head; prev != NULL; prev = prev->next)
        len++;
    if (n == len)
    {
        head = head->next;
        return (head);
    }
    for (prev = head; len - n > 1; prev = prev->next)
        len--;
    prev->next = prev->next->next;
    return (head);
}