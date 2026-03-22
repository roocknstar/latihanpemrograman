#include <stdio.h>

int hitungSewa(int hari) {
    return hari * 150000;
}

int main() {
    int lama, biaya;
    FILE *file;

    printf("Lama sewa kendaraan (hari): ");
    scanf("%d", &lama);

    biaya = hitungSewa(lama);

    file = fopen("sewa_kendaraan.txt", "w");
    fprintf(file, "Lama Sewa: %d hari\nTotal Biaya: Rp %d\n", lama, biaya);
    fclose(file);

    printf("Biaya Rp %d. Data disimpan ke sewa_kendaraan.txt\n", biaya);
    return 0;
}