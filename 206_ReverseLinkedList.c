#include <stdio.h>

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode *prev = NULL;
    struct ListNode *next;
    
    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
