#include <stdio.h>

int main() {
    int nim[4] = {825250017, 825250018, 825250020, 825250153};
    float nilai[4] = {88.5, 92.0, 75.5, 80.0};
    int i, cari, ketemu = 0;
    FILE *data;

    printf("Masukkan NIM yang dicari: ");
    scanf("%d", &cari);

    data = fopen("hasil_mahasiswa.txt", "w");
    for (i = 0; i < 4; i++) {
        if (nim[i] == cari) {
            printf("NIM: %d, Nilai: %.2f\n", nim[i], nilai[i]);
            fprintf(data, "Pencarian Berhasil!\nNIM: %d\nNilai: %.2f\n", nim[i], nilai[i]);
            ketemu = 1;
        }
    }

    if (ketemu == 0) {
        printf("NIM tidak ditemukan.\n");
        fprintf(data, "NIM %d tidak ada dalam sistem.\n", cari);
    }
    fclose(data);
    return 0;
}