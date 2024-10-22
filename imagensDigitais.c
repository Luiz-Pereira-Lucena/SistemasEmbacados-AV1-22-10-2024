#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 1080
#define MAX_COLS 1920

int main() {
    int rows, cols, value;

    printf("Digite o número de linhas (máx 1080): ");
    scanf("%d", &rows);
    if (rows > MAX_ROWS) rows = MAX_ROWS;

    printf("Digite o número de colunas (máx 1920): ");
    scanf("%d", &cols);
    if (cols > MAX_COLS) cols = MAX_COLS;

    unsigned char matrix[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            do {
                printf("Digite um valor entre 0 e 255 para a posição [%d][%d]: ", i, j);
                scanf("%d", &value);
            } while (value < 0 || value > 255);
            matrix[i][j] = (unsigned char)value;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 255 - matrix[i][j];
        }
    }

    printf("Matriz Invertida:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}


