#include <stdio.h>

int main() {
    int baris = 4;
    char huruf = 'A';

    for (int i = 1; i <= baris; i++) {
        for (int spasi = 1; spasi <= baris - i; spasi++) {
            printf("  ");
        }

        for (int j = 1; j <= i; j++) {
            printf("%c ", huruf);
            huruf++;
        }
        
        printf("\n");
    }

    return 0;
}