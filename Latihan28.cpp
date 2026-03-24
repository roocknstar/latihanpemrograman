#include <stdio.h>

int main() {
    int angka[10];
    int i;
    
    for (i = 0; i < 10; i++) {
        printf("Masukkan bilangan ke-%d: ", i + 1);
        scanf("%d", &angka[i]);
    }

    printf("\nBilangan Genap: ");
    for (i = 0; i < 10; i++) {
        if (angka[i] % 2 == 0) {
            printf("%d ", angka[i]);
        }
    }

    printf("\nBilangan Ganjil: ");
    for (i = 0; i < 10; i++) {
        if (angka[i] % 2 != 0) {
            printf("%d ", angka[i]);
        }
    }

    printf("\n");
    
    return 0;
}