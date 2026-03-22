#include <stdio.h>

int main() {
    float total_belanja;
    int member;

    printf("Total belanja: ");
    scanf("%f", &total_belanja);
    printf("Apakah Anda member? (1 = Ya, 0 = Tidak): ");
    scanf("%d", &member);

    if(member != 0 && member != 1) {
        printf("Input tidak valid. Harap masukkan 1 untuk Ya atau 0 untuk Tidak.\n");
        return 0;
    }

    printf("\n--- HASIL DISKON ---\n");
    if (member == 1) {
        if (total_belanja > 500000.0) {
            printf("Selamat! Anda mendapatkan diskon 20%%\n");
            printf("Total belanja Anda setelah diskon: Rp %.2f\n", total_belanja * 0.8);
        } else {
            printf("Selamat! Anda mendapatkan diskon 10%%\n");
            printf("Total belanja Anda setelah diskon: Rp %.2f\n", total_belanja * 0.9);
        }
    } else {
        if (total_belanja > 500000.0) {
            printf("Selamat! Anda mendapatkan diskon 5%%\n");
            printf("Total belanja Anda setelah diskon: Rp %.2f\n", total_belanja * 0.95);
        } else {
            printf("Maaf, Anda belum bisa mendapatkan diskon\n");
            printf("Total belanja Anda: Rp %.2f\n", total_belanja);
        }
    }

    return 0;
}