#include <stdio.h>
#include <stdlib.h>
/*/
first part of this is the 1.1 exercise where i improve on the matrix Transpose code, I defined some helper function to print the transpose 
and in main can take user input. I also defined the create_matrix function.
*/
/* exercise 1.1
typedef struct {
    int rows;
    int cols;
    float* data;
} matrix_t;

matrix_t create_matrix(int cols, int rows){

    matrix_t m;
    m.rows = rows;
    m.cols = cols;
    m.data = (float*)malloc(sizeof(float)*rows*cols);
    return m;
}

matrix_t matrix_transpose(matrix_t m) {
    matrix_t mt = create_matrix(m.cols, m.rows);

    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            mt.data[j * m.rows + i] = m.data[i * m.cols + j];
        }
    }

    return mt;
}

void printMatrix(matrix_t m){
    printf("\n");
    for(int i = 0; i < m.rows ; i++){
        for(int j = 0; j < m.cols; j++){
            printf("%6.2f", m.data[i * m.cols + j]);
        }
        printf("\n");
    }

}

int main(void){
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of cols: ");
    scanf("%d", &cols);
    
    matrix_t A = create_matrix(cols, rows);

    printf("\nEnter matrix elements row by row: \n");
    for(int i = 0 ; i < A.rows; i++){
        for(int j = 0 ; j < A.cols; j++){
            scanf("%f", &A.data[i * A.cols + j]);
        }
    }

    printMatrix(A);
    matrix_t At = matrix_transpose(A);

    printMatrix(At);

    return 0;
}
*/

void FizzBuzz(int n){
    if((n % 3 == 0) && (n % 5 == 0)){
        printf("\n%d: FizzBuzz\n", n);
    }
    else if(n % 3 == 0){
        printf("\n%d: Fizz", n);
    }
    else if(n % 5 == 0){
        printf("\n%d: Buzz\n", n);
    }
    
}
int compareDesc(const void *a, const void *b) {
    const int* a;
    const int* b;
    int A = *(const int*)a;
    int B = *(const int*)b;
    if (A < B) return 1;
    if (A > B) return -1;  
    return 0;
}

int main(void){
    
    int *arr = malloc(sizeof(int)*20);

    if(arr ==NULL){
        printf("Memory allocation failed \n");
    }

    for(int i =0; i < 20; i++){
        *(arr + 1)= (i + 1);
    }
    printf("fizzbuzz array 20:\n");
    for(int i =0; i <= 20;i++){
        FizzBuzz(*(arr + i));
    }

    free(arr);

    printf("fizzbuzz array 30: \n");
    for (int i = 1; i <= 30; i++) {
        FizzBuzz(i);
    }
    printf("\nArray before qsort:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    qsort(arr, 20, sizeof(int), compareDesc);

    printf("Array after qsort (descending):\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // free dynamically allocated memory
    return 0;

}