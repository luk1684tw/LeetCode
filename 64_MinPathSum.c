int minPathSum(int** grid, int gridSize, int* gridColSize){
    int** record = (int**) malloc(sizeof(int*) * gridSize);
    for (int i = 0; i < gridSize; i++) {
        record[i] = (int*) malloc(*gridColSize * sizeof(int));
    }
    record[0][0] = grid[0][0];

    for (int i = 1; i < gridSize; i++) {
        record[i][0] = record[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i < *gridColSize; i++) {
        record[0][i] = record[0][i - 1] + grid[0][i];
    }

    for (int i = 1; i < gridSize; i++) {
        for (int j = 1; j < *gridColSize; j++) {
            record[i][j] = ( (record[i - 1][j] < record[i][j - 1]) ? record[i - 1][j]: record[i][j - 1] ) + grid[i][j];
        }
    }

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            printf("%d ", record[i][j]);
        }
        printf("\n");
    }
    int tmp = record[gridSize - 1][(*gridColSize) - 1];

    for (int i = 0; i < gridSize; i++) {
        free(record[i]);
    }
    return tmp;
}