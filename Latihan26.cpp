#include <stdio.h>

int main() {
    int i, bintang, spasi;
    int tinggi = 5;

    for (i = 5; i >= 1; i -= 2){
        for (spasi = 1; spasi <= (5 - i) / 2; spasi++) {
            printf(" ");
        }
        for (bintang = 1; bintang <= i; bintang++) {
            printf("*");
        }
        printf("\n");
    }

    for (i = 1; i <= 5; i += 2){
        for (spasi = 1; spasi <= (5 - i) / 2; spasi++) {
            printf(" ");
        }
        for (bintang = 1; bintang <= i; bintang++) {
            printf("*");
        }
        printf("\n");
    }
    
return 0;
}