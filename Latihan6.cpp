#include <stdio.h>

float hitungRataRata(float nilai[], int jumlah) {
    float total = 0.0;
    int i;
    for(i = 0; i < jumlah; i++) {
        total += nilai[i];
    }
    return total / jumlah;
}

int main() {
    float nilai[5];
    int jumlah_nilai;
    int i;

    printf("--- NILAI TUGAS ALGORITMA ---\n");
    printf("Masukkan jumlah nilai yang akan dihitung (maks 5): ");
    scanf("%d", &jumlah_nilai);

    if(jumlah_nilai <= 0 || jumlah_nilai > 5) {
        printf("Jumlah nilai harus antara 1 dan 5.\n");
        return 0;
    }

    for(i = 0; i < jumlah_nilai; i++) {
        printf("Masukkan nilai ke-%d: ", i + 1);
        scanf("%f", &nilai[i]);
    }

    printf("Rata-rata nilai: %.2f\n", hitungRataRata(nilai, jumlah_nilai));

    return 0;
}