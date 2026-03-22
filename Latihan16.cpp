#include <stdio.h>

int main() {
    int ruangan[5] = {101, 102, 103, 104, 105};
    int kapasitas[5] = {30, 40, 20, 50, 25};
    int cari_ruang, i, status = 0;
    FILE *f;

    printf("Cari kapasitas ruangan: ");
    scanf("%d", &cari_ruang);

    f = fopen("info_ruangan.txt", "w");
    for (i = 0; i < 5; i++) {
        if (ruangan[i] == cari_ruang) {
            printf("Ruangan %d memiliki kapasitas %d orang\n", ruangan[i], kapasitas[i]);
            fprintf(f, "Info Ruangan\nNomor: %d\nKapasitas: %d\n", ruangan[i], kapasitas[i]);
            status = 1;
        }
    }

    if (status == 0) {
        printf("Ruangan tidak terdaftar.\n");
        fprintf(f, "Pencarian Gagal. Ruang %d tidak terdaftar.\n", cari_ruang);
    }
    fclose(f);
    return 0;
}