int findMin(int* nums, int numsSize)
{
    int left = 0;
    int right = numsSize - 1;
    int mid;
    int min = 5000;
    while (left <= right)
    {
        mid = left + (right - left)/2;
        if (nums[mid] < nums[right])
        {
            if(min > nums[mid])
                min = nums[mid];
            right = mid - 1;
        }
        else
        {
            if(min > nums[right])
                min = nums[right];
            left = mid + 1;
        }
    }
    return(min);
}