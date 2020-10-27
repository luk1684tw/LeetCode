char ** fizzBuzz(int n, int* returnSize)
{
    *returnSize = n;
    char** ans = (char **) malloc(sizeof(char*) * n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", i);
        if (i % 15 == 0)
        {
            ans[i - 1] = (char*) malloc(sizeof(char) * 9);
            sprintf(ans[i - 1], "%s", "FizzBuzz");
        } else if (i % 3 == 0)
        {
            ans[i - 1] = (char*) malloc(sizeof(char) * 5);
            sprintf(ans[i - 1], "%s", "Fizz");
        } else if (i % 5 == 0)
        {
            ans[i - 1] = (char*) malloc(sizeof(char) * 5);
            sprintf(ans[i - 1], "%s", "Buzz");
        } else
        {
            ans[i - 1] = (char*) malloc(sizeof(char) * 9);
            sprintf(ans[i - 1], "%d", i);
        }
    }
    return ans;
}