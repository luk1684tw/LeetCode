#include <stdio.h>



int titleToNumber(char * s)
{
    int ans = 0;
    int length = 0;
    while(s[length++] != '\0');
    for (int i = 0; i < length - 1; i++) 
    {
        ans *= 26;
        ans += s[i] - 'A' + 1;
        printf("%d\n", ans);
    }
    return ans;
}

int main(void)
{
    char input[7];
    gets(input);

    int ans = titleToNumber(input);
    printf("%d\n", ans);

    return 0;
}