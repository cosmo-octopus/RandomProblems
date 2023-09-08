int minEatingSpeed(int* piles, int pilesSize, int h)
{
    int low = 1;
    int high = 1e9;
    int i = 0;
    unsigned int counter = 0;
    int mid;
    while(low <= high)
    {
        mid = low + (high - low)/2;
        while (i < pilesSize)
        {
            if (piles[i] % mid != 0)
                counter += piles[i] / mid + 1;
            else
                counter += piles[i] / mid;
            i++;
        }
        i = 0;
        if (counter <= h)
            high = mid - 1;
        else
            low = mid + 1;
        counter = 0;
    }
    return(low);
}
