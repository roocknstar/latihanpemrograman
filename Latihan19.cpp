#include <stdio.h>

float angka1 = 0.0f; 
float angka2 = 0.0f;

void iangka1() {
    printf("Masukkan angka pertama: ");
    scanf("%f", &angka1); 
}

void iangka2() {
    printf("Masukkan angka kedua: ");
    scanf("%f", &angka2); 
}

void tambah() {
    float hasil = angka1 + angka2;
    printf("Hasil Penjumlahan (%.2f + %.2f) adalah %.2f\n", angka1, angka2, hasil);
}

void kurang() {
    float hasil = angka1 - angka2;
    printf("Hasil Pengurangan (%.2f - %.2f) adalah %.2f\n", angka1, angka2, hasil);
}

void kali() {
    float hasil = angka1 * angka2;
    printf("Hasil Perkalian (%.2f x %.2f) adalah %.2f\n", angka1, angka2, hasil);
}

void bagi() {
    if (angka2 != 0.0f) { 
        float hasil = angka1 / angka2;
        printf("Hasil Pembagian (%.2f / %.2f) adalah %.2f\n", angka1, angka2, hasil);
    } else {
        printf("Angka tidak dapat dibagi dengan nol.\n");
    }
}


int main() {
    char operasi;
    int program = 1; 

    while (program == 1) {
        printf("\nSilakan Masukan Angka!\n");
        iangka1(); 
        iangka2();
        
        printf("Pilih '+' untuk penjumlahan\nPilih '-' untuk pengurangan\nPilih '*' untuk perkalian\nPilih '/' untuk pembagian\n");
        printf("Pilih 'K' untuk keluar dari program\n");
        printf("Pilih operasi: ");
        
        scanf(" %c", &operasi);

        switch (operasi) {
            case '+':
                tambah(); 
                break;
            case '-':
                kurang();
                break;
            case '*':
                kali();
                break;
            case '/':
                bagi();
                break;
            case 'K':
            case 'k':
                program = 0;
                break;
            default:
                printf("Kamu salah menekan tombol.\n");
                break;
        }
    }

    printf("\nAnda telah keluar dari program.\n");
    return 0;
}