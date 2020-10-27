int calculateLen(char *s)
{  
    int lenS = 0;
    char *tmp = s;
    while (*tmp != '\0')
    {
        lenS++;
        tmp++;
    }
    return lenS;
}

void countAlpha(char* stringA, int* countA, char* stringB, int* countB)
{
    while(*stringA != '\0')
    {
        countA[*stringA - 'a']++;
        stringA++;
        
        countB[*stringB - 'a']++;
        stringB++;
    }
    return;
}

bool isAnagram(char * s, char * t)
{
    int lenS = calculateLen(s), lenT = calculateLen(t);

    if (lenS != lenT)
        return false;
    int countS[26] = {0};
    int countT[26] = {0};

    countAlpha(s, countS, t, countT);

    for (int i = 0; i < 26; i++)
    {
        if (countS[i] != countT[i])
        {
            return false;
        }
    }
    return true;
}