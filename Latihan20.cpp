#include <stdio.h>

int main(){
    int x;
    int y;

    printf("Masukkan bilangan integer positif (x): ");
    scanf("%d", &x);

    printf("Masukkan bilangan integer (y): ");
    scanf("%d", &y);

    int deret;
    if (x < 0){
        printf("Bilangan integer x harus bernilai positif.");
    } else {
        printf("Deret:\n");
        for (int i = 0; i < x; i++) {
            int angka_deret = y + (i * x);
            printf("%d ", angka_deret);
        }
        printf("\n");
    }
    return 0;
}