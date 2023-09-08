// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) 
{
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low)/2;
        if (isBadVersion(mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return(low);
}