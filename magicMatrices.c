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

void matriceCopy(const int *A, const int N, int *Copy, const int iIniCpy, const int jIniCpy, const int copyN){
    int i, j, iCpy = iIniCpy, jCpy;
    for(i = 0; i < N; i++, iCpy++){
        jCpy = jIniCpy;
        for(j = 0; j < N; j++, jCpy++)
            *(Copy + copyN*iCpy + jCpy) = *(A + N*i + j);
    }
    return;
}

void matrixSwap(int *A, const int N, const int iA, const int jA, const int iB, const int jB){
    int aux = *(A + N*iA + jA);
    *(A + N*iA + jA) = *(A + N*iB + jB);
    *(A + N*iB + jB) = aux;
    return;
}

void singlyEvenMatrixPermutator(int *A, const int N, const int iniTerm){
    int i = 0, j = N/2, k, endTerm = N*N + iniTerm;
    for(k = iniTerm; k <= endTerm; k++){
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

void singlyEvenMatrixAuxiliar(int *A, const int N){
    int auxDim = N/2, term = 1;
    int Aux[auxDim][auxDim];
    singlyEvenMatrixPermutator(Aux, auxDim, term);
    matriceCopy(Aux, auxDim, A, 0, 0, N);

    term += auxDim*auxDim;
    singlyEvenMatrixPermutator(Aux, auxDim, term);
    matriceCopy(Aux, auxDim, A, auxDim, auxDim, N);

    term += auxDim*auxDim;
    singlyEvenMatrixPermutator(Aux, auxDim, term);
    matriceCopy(Aux, auxDim, A, 0, auxDim, N);

    term += auxDim*auxDim;
    singlyEvenMatrixPermutator(Aux, auxDim, term);
    matriceCopy(Aux, auxDim, A, auxDim, 0, N);

    return;
}

void singlyEvenMatrixColumnPermutator(int *A, const int N){
    int i, j, leftLim = (N - 2)/4, rightLim, half = N/2, quarter = N/4, count;
    rightLim = leftLim - 1;
    for(i = 0; i < half; i++)
        for(j = 0; j < leftLim; j++){
            if(i == quarter)
                matrixSwap(A, N, i, j + 1, i + half, j + 1);
            else
                matrixSwap(A, N, i, j, i + half, j);
        }
    for(i = 0; i < half; i++){
        count = 0;
        for(j = N - leftLim + 1; count < rightLim; j++, count++)
            matrixSwap(A, N, i, j, i + half, j);
    }
    return;
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

void singlyEvenMagicMatrixConstructor(int *A, const int N){
    int i, j, half = N/4 + 1;
    singlyEvenMatrixAuxiliar(A, N);
    singlyEvenMatrixColumnPermutator(A, N);
    return;
}

void doublyEvenMagicMatrixConstructor(int *A, const int N){
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

boolean continua(void){
    char ch;
    system("cls");
    puts("Deseja executar novamente? <S/N>");
    do{
        ch = getchar();
    }while(ch != 's' && ch != 'n' && ch != 'S' && ch != 'N');
    if(ch == 's' || ch == 'S')
        return(1);
    else
        return(0);
}


int main(void){
    char numInput[2], ch;
    int N;
    do{
        do{
            numValidate(numInput, &N, "Escolha a ordem da matriz a ser gerada (no intervalo de 3 a 10 apenas)");
        }while(N < 3 || N > 10);
        int A[N][N];
        matrixFill(A, N);
        if(N % 2 != 0)
            oddMagicMatrixConstructor(A, N);
        else if(N % 4 == 0)
            doublyEvenMagicMatrixConstructor(A, N);
        else
            singlyEvenMagicMatrixConstructor(A, N);
        system("cls");
            matrixPrint(A, N);
        system("Pause");
    }while(continua());
    return(0);
}
