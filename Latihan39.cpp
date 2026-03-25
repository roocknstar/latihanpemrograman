#include <stdio.h>

void bagiArray(int array[], int ukuran, int pembagian, int arrayA[], int arrayB[], int *ukuran1, int *ukuran2) {
    *ukuran1 = 0;
    *ukuran2 = 0;
    
    for (int i = 0; i < pembagian; i++) {
        arrayA[i] = array[i];
        (*ukuran1)++;
    }
    
    for (int i = pembagian; i < ukuran; i++) {
        arrayB[i - pembagian] = array[i];
        (*ukuran2)++;
    }
}

int main() {
    int arrAwal[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int ukuran = sizeof(arrAwal) / sizeof(arrAwal[0]);
    int pembagian = 4;
    int arrayA[ukuran], arrayB[ukuran];
    int ukuran1, ukuran2;

    printf("Array Awal : [ ");
    for(int i=0; i<ukuran; i++){
        printf("%d ", arrAwal[i]);
    }
    printf("]");

    bagiArray(arrAwal, ukuran, pembagian, arrayA, arrayB, &ukuran1, &ukuran2);

    printf("\nArray A    : [ ");
    for(int i=0; i<ukuran1; i++){
        printf("%d ", arrayA[i]);
    }
    printf("]");

    printf("\nArray B    : [ ");
    for(int i=0; i<ukuran2; i++) {
        printf("%d ", arrayB[i]);
    }
    printf("]");
    
    printf("\n");

    return 0;
}