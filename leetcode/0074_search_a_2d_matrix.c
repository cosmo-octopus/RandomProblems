bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){

    int low = 0;
    int high = matrixSize * *matrixColSize - 1;
    while (low <= high) 
    {
        int mid = (high + low) / 2;
        int row = mid / *matrixColSize;
        int col = mid % *matrixColSize;
        if (matrix[row][col] < target) 
            low = mid + 1;
        else if (matrix[row][col] > target) 
            high = mid - 1;
        else
            return true;
    }
    return false;
}
