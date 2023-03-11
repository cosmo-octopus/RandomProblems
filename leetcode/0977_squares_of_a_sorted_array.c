/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    int* return_arr =  malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++)
        return_arr[i] = nums[i] * nums[i];
    //quicksort
    quicksort(return_arr, 0, numsSize - 1);
    return(return_arr);
}

void quicksort(int* number, int first, int last)
{
   int i, j, pivot, temp;
   if (first < last)
   {
      pivot = first;
      i = first;
      j = last;
      while(i < j)
      {
         while(number[i] <= number[pivot] && i<last)
         i++;
         while(number[j] > number[pivot])
         j--;
         if(i < j){
            temp = number[i];
            number[i] = number[j];
            number[j] = temp;
         }
      }
      temp = number[pivot];
      number[pivot] = number[j];
      number[j] = temp;
      quicksort(number, first, j - 1);
      quicksort(number, j + 1, last);
   }
}