#include <stdio.h>
#include <stdlib.h>

void matrixPrint(const int *A, const int N){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++)
            printf("%4d", *(A + N*i + j));
        printf("\n");
    }
}

void oddMagicMatrixConstructor(int *A, const int N){
    int i = 0, j = N/2, k, endTerm = N*N;
    for(k = 1; k <= endTerm; k++){
        *(A + N*i + j) = k;
        i--;
        j++;
        if(k % N == 0){
            i += 2;
            j--;
        }else if(j == N)
                j -= N;
            else if(i < 0)
                i += N;
    }
}



int main(void){
    int A[3][3];
    oddMagicMatrixConstructor(A, 3);
    matrixPrint(A, 3);
    system("Pause");
    return(0);
}
