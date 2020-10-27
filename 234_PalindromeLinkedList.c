bool isPalindrome(struct ListNode* head)
{
    int length = 0;
    struct ListNode* tmp = head;
    while(tmp != NULL)
    {
        length++;
        tmp = tmp->next;
    }

    int* arr = (int *) malloc(sizeof(int) * length);
    tmp = head;
    int idx = 0;
    while (tmp != NULL)
    {
        arr[idx++] = tmp->val;
        tmp = tmp->next;
    }

    for (int i = 0; i < length / 2; i++)
    {
        if (arr[i] != arr[length - i - 1])
            return false;
    }
    free(arr);
    return true;
}