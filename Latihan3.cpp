#include <stdio.h>

int main() {
    int tebakan;
    int angka_rahasia = 42; 
    int tebakan_benar = 0;

    printf("--- GAME TEBAK ANGKA ---\n");
    
    while (tebakan_benar == 0) {
        printf("Masukkan tebakan Anda: ");
        scanf("%d", &tebakan);

        if (tebakan == angka_rahasia) {
            printf("Selamat! Tebakan Anda benar.\n");
            tebakan_benar = 1;
        } else if (tebakan < angka_rahasia) {
            printf("Tebakan terlalu kecil.\n");
        } else {
            printf("Tebakan terlalu besar.\n");
        }
    }

    return 0;
}