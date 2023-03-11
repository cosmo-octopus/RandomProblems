void rotate(int* nums, int numsSize, int k)
{
    int* new_arr = malloc(sizeof(int) * numsSize);
    int x = 0;
    int j;
    if(k > numsSize)
        j = numsSize - k % numsSize;
    else
        j = numsSize - k;
    for(int i = 0; i < numsSize; i++)
    {
        if(j < numsSize)
        {
            new_arr[i] = nums[j];
            j++;
        }    
        else
        {
            new_arr[i] = nums[x];
            x++;
        }
        
    }
    for(int num = 0; num < numsSize; num++)
        nums[num] = new_arr[num];
    free(new_arr);
}