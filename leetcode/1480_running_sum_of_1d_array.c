// Note: The returned array must be malloced, assume caller calls free().

int* runningSum(int* nums, int numsSize, int* returnSize)
{
    int* sum = (int*)malloc(numsSize * sizeof(int));
    sum[0] = nums[0];
    int i = 1;
    while (i < numsSize)
    {  
        sum[i] = sum[i - 1] + nums[i];
        i++;
    }
    *returnSize = numsSize;
    return(sum);
}
