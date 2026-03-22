#include <stdio.h>

int main() {
    int tujuan, jumlah, harga, total;
    FILE *arsip;

    printf("1. Jakarta (Rp 500000)\n2. Bali (Rp 800000)\nPilih tujuan (1/2): ");
    scanf("%d", &tujuan);
    printf("Jumlah tiket: ");
    scanf("%d", &jumlah);

    if (tujuan == 1) {
        harga = 500000;
    } else if (tujuan == 2) {
        harga = 800000;
    } else {
        harga = 0;
    }

    total = harga * jumlah;

    arsip = fopen("tiket_pesawat.txt", "w");
    fprintf(arsip, "=== STRUK PESAWAT ===\n");
    fprintf(arsip, "Tujuan: %d\nJumlah: %d\nTotal Bayar: Rp %d\n", tujuan, jumlah, total);
    fclose(arsip);

    printf("Total Rp %d. Disimpan ke tiket_pesawat.txt\n", total);
    return 0;
}