/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if(head==NULL || head->next == NULL || k == 0)
        return head;
    struct ListNode *null, *new_head;
    int len = length(head);
    len = k % len;
    for(int i = 0; i < len; i++)
    {
        for(null = head;null->next->next != NULL;null = null->next){}
        new_head = null->next;
        null->next = NULL;
        new_head->next = head;
        head = new_head;
    }
    return (new_head);
}

int length(struct ListNode* head) 
{
    struct ListNode* current = head;
    int counter = 0;
    while (current != NULL) 
    {
        counter++;
        current = current->next;
    }
    return (counter);
}