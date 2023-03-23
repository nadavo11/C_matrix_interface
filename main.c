#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10
/************************************************************************
 *                                                                      *
 *                    declarations & helpers                             *
 *                                                                      *
 ********************************************************************** */
int mat1[ROWS][COLS], mat2[ROWS][COLS], resmat[ROWS][COLS], mau[ROWS][COLS];

void printMatrix(int matrix[][COLS]) {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%d, ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printMenu(int matrix[][COLS]) {
    printf("--- Menu ---\n");
    printf("1) Create two 10x10 matrices Mat1,Mat2 using the next expression: for i,j Mat1[i][j] - (offset + i*10 + j) % 100\n");
    printf("2) Compute and show the matrix Mat1 + Mat2\n");
    printf("3) Compute and show the maximal Trace between matrices Matt and Mat1\n");
    printf("4) Compute and show the combined maximal matrix between Matu and Matt\n");
    printf("5) Swap between primary diagonal and the secondary diagonal according to user choice\n");
    printf("6) Sort a given line in a given matrix\n");
    printf("7) Show a given Matrix\n");
    printf("8) Show menu\n");
    printf("9) Exit\n");
}

/************************************************************************
 *                                                                      *
 *                    1 - create matz with offsets                      *
 *                                                                      *
 ********************************************************************** */
void createMatrices(int offset) {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            mat1[i][j] = (offset + i*10 + j) % 100;
            mat2[i][j] = (offset + i*10 + j) % 100;
            resmat[i][j] = mat1[i][j] + mat2[i][j];
            //mat4[i][j] = (offset + i*10 + j) % 100;
        }
    }
    printf("\nMats created!\n");
}

/************************************************************************
 *                                                                      *
 *               2 - Compute and show the materix Mat1+Mat2             *
 *                                                                      *
 ********************************************************************** */

void addAndPrintMats() {
    int i, j;
    int result[ROWS][COLS];
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printf("\nMat1 + Mat2:\n");
    printMatrix(result);
}
/************************************************************************
 *                                                                      *
 *            3 - Compute and show the max trace of Mat1 & Mat2         *
 *                                                                      *
 ********************************************************************** */
void computeAndPrintMaximalTrace() {
    int i, j;
    int trace1,trace2 = 0;

    //add all of the diagonal ellements
    for(i=0; i<ROWS; i++) {
        trace1 += mat1[i][i];
        trace2 += mat2[i][i];
    }

    trace1>trace2 ? printf("\nMaximal Trace: %d\n",trace1) : printf("\nMaximal Trace: %d\n",trace2);

}
/************************************************************************
 *                                                                      *
 *            4 - Compute and show the max matrix of Mat1 & Mat2        *
 *                                                                      *
 ********************************************************************** */

void printCombinedMaxMatrix() {
    int i, j;
    int result[ROWS][COLS];
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            result[i][j] = mat1[i][j] > mat2[i][j] ? mat1[i][j] : mat2[i][j];
        }
    }
    printf("\nCombined Maximal Matrix:\n");
    printMatrix(result);
}

/************************************************************************
 *                                                                      *
 *            5 - Swap prmary & secondary diagonals                     *
 *                                                                      *
 ********************************************************************** */
void swapDiagonal(int (* matt)[COLS]) {

    int i;
    //for each diagonal entry
    for(i=0; i<ROWS; i++) {

        //switch primary with secondary
        int temp = matt[i][i];
        matt[i][i] = matt[i][COLS-i];
        matt[i][COLS-i] = temp;
    }

    printf("\nDiagonal swapped successfully!\n");
}


void sortMatrixLine(int (* matt)[COLS],int line) {
    int i, j;

    //bubble sort
    for(i=0; i<COLS; i++) {
        for(j=i+1; j<COLS; j++) {
            if(matt[line][j] < matt[line][i]) {
                //switch entries
                int temp = matt[line][i];
                matt[line][i] = matt[line][j];
                matt[line][j] = temp;
            }
        }
    }
    printf("\nLine sorted successfully!\n");
}

int main() {
    int choice, offset;
    printf("--- Menu ---\n");
    printf("1) Create two 10x10 matrices Mat1,Mat2 using the next expression: for i,j Mat1[i][j] - (offset + i*10 + j) % 100\n");
    printf("2) Compute and show the matrix Mat1 + Mat2\n");
    printf("3) Compute and show the maximal Trace between matrices Matt and Mat1\n");
    printf("4) Compute and show the combined maximal matrix between Matu and Matt\n");
    printf("5) Swap between primary diagonal and the secondary diagonal according to user choice\n");
    printf("6) Sort a given line in a given matrix\n");
    printf("7) Show a given Matrix\n");
    printf("8) Show menu\n");
    printf("9) Exit\n");
    int q = 1;
    while (q) {

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        int mat, line;

        switch (choice) {
            case 1:
                printf("\nInsert offset number in range 0-9 for Mat1 generation ");
                scanf("%d", &offset);
                createMatrices(offset);
                break;
            case 2:
                addAndPrintMats();
                break;
            case 3:
                computeAndPrintMaximalTrace();
                break;
            case 4:
                printCombinedMaxMatrix();
                break;
            case 5:
                printf("Insert the wanted matrix by its number identifier\n"
                       "                1: Mat1, 2: Mat2, 3: resMat 3");
                scanf("%d", &mat);

                if (mat == 1)
                    swapDiagonal(mat1);
                if (mat == 2)
                    swapDiagonal(mat2);
                if (mat == 3)
                    swapDiagonal(resmat);
                break;
            case 6:

                printf("Insert the wanted matrix by its number identifier\n1: Mat1, 2: Mat2, 3: resMat");
                scanf("%d", &mat);

                printf("\nInsert matrix line number to sort in range 0-9 ");
                scanf("%d", &line);
                if (mat == 1)
                    sortMatrixLine(mat1, line);
                if (mat == 2)
                    sortMatrixLine(mat2, line);
                if (mat == 3)
                    sortMatrixLine(resmat, line);


                break;
            case 7:

                printf("Insert the wanted matrix by its number identifier\n"
                       "                1: Mat1, 2: Mat2, 3: resMat 3");
                scanf("%d", &mat);

                if (mat == 1)
                    printMatrix(mat1);
                if (mat == 2)
                    printMatrix(mat2);
                if (mat == 3)
                    printMatrix(resmat);
                break;
            default:
                q = 0;

        }
    }
}
