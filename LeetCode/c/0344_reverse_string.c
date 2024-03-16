void reverseString(char* s, int sSize)
{
    int low = 0;
    int high = sSize - 1;
    char temp;
    while(low < high)
    {
        temp = s[low];
        s[low] = s[high];
        s[high] = temp;
        low++;
        high--;
    }
}