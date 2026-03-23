#include <stdio.h>

int main() {
    int n;
    char c1, c2, c3;

    printf("Masukkan ukuran persegi: ");
    scanf("%d", &n);

    printf("Masukkan karakter pertama C1 (batas atas & bawah): ");
    scanf(" %c", &c1);
    
    printf("Masukkan karakter kedua C2 (batas kanan & kiri): ");
    scanf(" %c", &c2);

    printf("Masukkan karakter ketiga C3 (dalam): ");
    scanf(" %c", &c3);

    printf("\nBentuk Visual:\n");

    for (int baris = 1; baris <= n; baris++) {
        for (int kolom = 1; kolom <= n; kolom++) {
            if (baris == 1 || baris == n) {
                printf("%c ", c1);
            }
            else if (kolom == 1 || kolom == n) {
                printf("%c ", c2);
            }
            else {
                printf("%c ", c3);
            }
        }
        printf("\n");
    }

    return 0;
}