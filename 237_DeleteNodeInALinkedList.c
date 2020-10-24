void deleteNode(struct ListNode* node)
{
    struct ListNode* tmp = node;
    while (tmp->next->next != NULL)
    {
        tmp->val = tmp->next->val;
        tmp = tmp->next;
    }
    struct ListNode* tail = tmp->next;
    tmp->val = tmp->next->val;
    tmp->next = NULL;
    free(tail);
    return;
}