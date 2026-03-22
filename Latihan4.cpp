#include <stdio.h>

float hitungBonus(int masa_kerja) {
    if (masa_kerja >= 3) {
        return 1500000.0;
    }
    return 0.0;
}

int main() {
    int peran, masa_kerja;
    float gaji_pokok = 0.0, total_gaji;

    printf("--- PENGHITUNGAN GAJI TIM ---\n");
    printf("Peran (1: Developer, 2: Designer, 3: Publikasi): ");
    scanf("%d", &peran);
    printf("Masa kerja (tahun): ");
    scanf("%d", &masa_kerja);

    switch (peran) {
        case 1: 
            gaji_pokok = 8000000.0; 
            break;
        case 2: 
            gaji_pokok = 7000000.0; 
            break;
        case 3: 
            gaji_pokok = 6500000.0; 
            break;
        default: 
            printf("Peran tidak valid.\n"); 
            return 0;
    }

    total_gaji = gaji_pokok + hitungBonus(masa_kerja);
    printf("Total Gaji: Rp %.2f\n", total_gaji);

    return 0;
}