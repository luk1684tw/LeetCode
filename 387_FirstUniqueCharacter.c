int firstUniqChar(char * s)
{
    int occu[26] = {0};
    char *tmp = s;
    while (*tmp != '\0')
    {
        occu[*tmp - 'a']++;
        tmp++;
    }

    int ans = 0;
    while (*s != '\0')
    {
        if (occu[*s - 'a'] == 1)
            return ans;
        ans++;
        s++;
    }
    return -1;
}