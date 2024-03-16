void swap(char *s, int l, int r) 
{
    while(l < r) 
    {
        char temp = s[l];
        s[l++] = s[r];
        s[r--] = temp;
    }
}

char * reverseWords(char * s)
{
    int sLen = strlen(s), wStart = 0, wEnd = 0;
    
    while(wEnd < sLen) 
    {
        while (wEnd < sLen && s[wEnd] != ' ') 
            wEnd++;
        swap(s, wStart, wEnd-1);
        wEnd++;
        wStart = wEnd;
    }
    return s;
}