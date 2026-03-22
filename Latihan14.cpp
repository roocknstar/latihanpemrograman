#include <stdio.h>

int main() {
    int harga_barang[3] = {5000, 3000, 1500};
    int beli, i = 0, total = 0;
    FILE *f;

    printf("Berapa jenis barang yang dibeli (maks 3)? ");
    scanf("%d", &beli);

    if (beli < 1 || beli > 3) {
        printf("Jumlah barang tidak valid. Harus antara 1 dan 3.\n");
        return 1;
    }

    while (i < beli && i < 3) {
        total += harga_barang[i];
        i++;
    }

    f = fopen("alat_tulis.txt", "w");
    fprintf(f, "Jumlah Barang: %d\nTotal Bayar: Rp %d\n", beli, total);
    fclose(f);

    printf("Total: Rp %d. Tersimpan.\n", total);
    return 0;
}