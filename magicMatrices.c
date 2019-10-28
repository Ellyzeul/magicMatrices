#include <stdio.h>
#include <stdlib.h>

typedef enum Boolean {f, v} boolean;

boolean charToInt(const char *String, int *num){
    int i;
    *num = 0;
    for(i = 0; *(String + i) != '\0'; i++){
        if(*(String + i) < 48 || *(String + i) > 57)
            return(0);
        *num *= 10;
        *num += *(String + i) - 48;
    }return(1);
}

void numValidate(const char *String, int *var, const char *msg){
    do{
        system("cls");
        puts(msg);
        gets(String);
    }while(!charToInt(String, var));
    return;
}

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

void matrixFill(int *A, const int N){
    int i, lim = N*N;
    for(i = 0; i < lim; i++)
        *(A + i) = i + 1;
    return;
}

void fourMultipleMagicMatrixConstructor(int *A, const int N){
    int i, j, constant = N*N + 1, section = N/4;
    matrixFill(A, N);

    for (i = 0; i < section; i++){
        for (j = 0; j < section; j++)
            *(A + N*i + j) = constant - *(A + N*i + j);
    }
    for (i = 0; i < section; i++){
        for (j = 3 * section; j < N; j++)
            *(A + N*i + j) = constant - *(A + N*i + j);
    }
    for (i = 3 * section; i < N; i++){
        for (j = 0; j < section; j++)
            *(A + N*i + j) = constant - *(A + N*i + j);
    }
    for (i = 3 * section; i < N; i++){
        for (j = 3 * section; j < N; j++)
            *(A + N*i + j) = constant - *(A + N*i + j);
    }
    for (i = section; i < 3 * section; i++){
        for ( j = section; j < 3 * section; j++)
            *(A + N*i + j) = constant - *(A + N*i + j);
    }return;
}


int main(void){
    char numInput[2];
    int N;
    do{
        numValidate(numInput, &N, "Escolha a ordem da matriz a ser gerada (no intervalo de 3 a 10 apenas)");
    }while(N < 3 || N > 10);
    int A[N][N];
    if(N % 2 != 0)
        oddMagicMatrixConstructor(A, N);
    else if(N % 4 == 0)
        fourMultipleMagicMatrixConstructor(A, N);
    system("cls");
    matrixPrint(A, N);
    system("Pause");
    return(0);
}
