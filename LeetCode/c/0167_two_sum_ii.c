/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    *returnSize = 2;
    int* return_arr = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    int j = numbersSize - 1;
    
    while(i < j)
    {
        int diff = target - (numbers[i] + numbers[j]);
        if(diff < 0)
            j--;
        else if(diff > 0)
            i++;
        else
        {
            return_arr[0] = i + 1;
            return_arr[1] = j + 1;
            return(return_arr);
        }
    }    
    return(0);
}