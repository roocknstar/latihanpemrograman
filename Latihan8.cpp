#include <stdio.h>

void konversiSuhu(int pilihan, float celcius) {
    float hasil;
    switch(pilihan) {
        case 1:
            hasil = (celcius * 9.0 / 5.0) + 32.0;
            printf("Fahrenheit: %.2f\n", hasil);
            break;
        case 2:
            hasil = celcius + 273.15;
            printf("Kelvin: %.2f\n", hasil);
            break;
        default:
            printf("Pilihan salah.\n");
    }
}

int main() {
    float suhu;
    int menu;

    printf("Masukkan suhu Celcius: ");
    scanf("%f", &suhu);
    
    printf("Konversi ke:\n1. Fahrenheit\n2. Kelvin\nPilih (1/2): ");
    scanf("%d", &menu);
    
    if(menu != 1 && menu != 2) {
        printf("Input tidak valid. Harap masukkan 1 untuk Fahrenheit atau 2 untuk Kelvin.\n");
        return 0;
    }

    konversiSuhu(menu, suhu);

    return 0;
}