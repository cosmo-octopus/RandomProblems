char* convert(char* s, int numRows) {
    if (numRows == 1) return s;

    int len = strlen(s);
    char* result = malloc(len + 1); // allocate memory for the result string
    result[len] = '\0'; // null terminate the result string

    // create a 2D array to store the characters in a zigzag pattern
    char** zigzag = malloc(numRows * sizeof(char*));
    for (int i = 0; i < numRows; i++) {
        zigzag[i] = malloc((len / 2 + 1) * sizeof(char));
        for (int j = 0; j <= len / 2; j++) {
            zigzag[i][j] = 0;
        }
    }

    int row = 0, col = 0;
    for (int i = 0; i < len; i++) {
        zigzag[row][col] = s[i];
        if (row == numRows - 1) {
            row--;
            col++;
        } else if (row == 0) {
            row++;
        } else if (col % (numRows - 1) == 0) {
            row++;
        } else {
            row--;
            col++;
        }
    }
    
    // iterate through the zigzag array and append the characters to the result string
    int resultIndex = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= col; j++) {
            if (zigzag[i][j] != '\0') {
                result[resultIndex] = zigzag[i][j];
                resultIndex++;
            }
        }
    }

    // free the memory allocated for the zigzag array
    for (int i = 0; i < numRows; i++) {
        free(zigzag[i]);
    }
    free(zigzag);

    return result;
}