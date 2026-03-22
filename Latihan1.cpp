#include <stdio.h>

int main() {
    int jumlah_barang, i;
    float total = 0.0;
    float harga[10];
    char nama_barang[50];

    printf("Masukkan jumlah barang (maks 10): ");
    scanf("%d", &jumlah_barang);

    if (jumlah_barang < 1 || jumlah_barang > 10) {
        printf("Jumlah barang harus antara 1 dan 10.\n");
        return 0;
    }

    for(i = 0; i < jumlah_barang; i++) {
        printf("\nMasukkan nama barang ke-%d: ", i + 1);
        scanf("%s", nama_barang);
        printf("Harga barang ke-%d: ", i + 1);
        scanf("%f", &harga[i]);
        total = total + harga[i];
    }

    printf("\n--- STRUK BELANJA ---\n");
    for(i = 0; i < jumlah_barang; i++) {
        printf("Nama Barang %d: %s\n", i + 1, nama_barang);
        printf("Barang %d: Rp %.2f\n\n", i + 1, harga[i]);
    }
    printf("Total Bayar: Rp %.2f\n", total);

    return 0;
}