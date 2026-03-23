#include <stdio.h>
    
int main() {
    int kiri = 7;
    int kanan = 10;

    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        
        printf("%d %d\n", kiri, kanan);

        if (i == 5) { 
            kiri = 15; kanan = 18; }
        else if (i == 4) { 
            kiri = 27; kanan = 24; }
        else if (i == 3) { 
            kiri = 42; kanan = 28; }
        else if (i == 2) { 
            kiri = 59; kanan = 30; }
    }

return 0;
}