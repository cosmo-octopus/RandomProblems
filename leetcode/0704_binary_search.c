int search(int* nums, int numsSize, int target)
{
    int min = 0;
    int max = numsSize - 1;
    
    
    while (min <= max)
    {
        int mid = (max + min)/2;
        if (target == nums[mid])
            return(mid);
        if (target > nums[mid])
            min = mid + 1;
        else
            max = mid - 1;
    }
    return(-1);   
}
