#include <stdio.h>

int main() {
    int tipe, breakfast, total;
    FILE *file;

    printf("Tipe Kamar (1. Single 2. Double 3. Twin): ");
    scanf("%d", &tipe);

    if(tipe < 1 || tipe > 3) {
        printf("Tipe kamar tidak valid.\n");
        return 1;
    }
    
    printf("Tambah Breakfast? (1. Ya 2. Tidak): ");
    scanf("%d", &breakfast);

    switch(tipe) {
        case 1: 
        total = 300000; 
        break;
        case 2: 
        total = 500000; 
        break;
        case 3: 
        total = 550000; 
        break;
        default: 
        total = 0;
    }

    if (total > 0) {
        if (breakfast == 1) {
            total += 50000;
        }
    }

    file = fopen("struk_hotel.txt", "w");
    fprintf(file, "=== STRUK HOTEL ===\nTipe Kamar: %d\nTotal Bayar: Rp %d\n", tipe, total);
    fclose(file);

    printf("Total Rp %d. Disimpan ke struk_hotel.txt\n", total);
    return 0;
}