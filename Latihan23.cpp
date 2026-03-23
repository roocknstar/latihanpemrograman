#include <stdio.h>

int main() {
    int baris = 5;

    for (int i = 0; i < baris; i++) {
        for (int spasi = 1; spasi <= (baris - i - 1); spasi++) {
            printf(" ");
        }

        int koefisien = 1;
        for (int j = 0; j <= i; j++) {
            printf("%d", koefisien);
            if (j < i) printf(" ");
            koefisien = koefisien * (i - j) / (j + 1);
        }
        
        printf("\n");
    }

return 0;
}