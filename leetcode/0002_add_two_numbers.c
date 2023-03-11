/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
   struct ListNode *newList, *q;
   struct ListNode* head = NULL;
   int sum = 0;
   while (l1 || l2 || sum != 0)
   {
       newList = malloc(sizeof(struct ListNode));
       if (l1)
       {
           sum += l1->val;
           l1 = l1->next;
       }
       if (l2)
       {
           sum += l2->val;
           l2 = l2->next;
       }
       newList->val = sum % 10;
       newList->next = NULL;
       sum = sum / 10;
       if (!head)
            head = newList;
       if(q)
           q->next = newList;
       q = newList;
   } 
   return (head);
}