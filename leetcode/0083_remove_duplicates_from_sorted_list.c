/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (!head)
        return NULL;
    struct ListNode *cur, *next;
    cur = head;
    next = cur->next;
    while (next)
    {
        if (cur->val != next->val)
        {
            cur->next = next;
            cur = next;
        }
        next = next->next;
    }
    cur->next = NULL;
    return (head);
}