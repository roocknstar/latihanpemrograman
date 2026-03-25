#include <stdio.h>

void duplikatArray(int arrayAwal[], int ukuranAwal, int arrayBaru[]) {
    int ukuranBaru = ukuranAwal * 2;
    
    for (int i = 0; i < ukuranAwal; i++) {
        arrayBaru[i] = arrayAwal[i];
    }
    
    for (int i = ukuranAwal; i < ukuranBaru; i++) {
        arrayBaru[i] = 0;
    }
}

int main() {
    int ukuranAwal = 5;
    int arrayAwal[5] = {100, 90, 80, 70, 60};
    int ukuranBaru = ukuranAwal * 2;
    int gandakanArray[10];

    duplikatArray(arrayAwal, ukuranAwal, gandakanArray);

    printf("Array Awal : [ ");
    for(int i=0; i<ukuranAwal; i++) {
        printf("%d ", arrayAwal[i]);
    }
    printf("]");

    printf("\nArray Baru : [ ");
    for(int i=0; i<ukuranBaru; i++) {
        printf("%d ", gandakanArray[i]);
    }
    printf("]");
    printf("\n");

    return 0;
}