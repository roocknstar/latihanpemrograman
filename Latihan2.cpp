#include <stdio.h>

int main() {
    int jam_masuk, jam_keluar, lama_parkir;
    int tarif_per_jam = 2000, total_bayar;

    printf("Masukkan jam masuk (1-24): ");
    scanf("%d", &jam_masuk);
    printf("Masukkan jam keluar (1-24): ");
    scanf("%d", &jam_keluar);

    if (jam_masuk < 1 || jam_masuk > 24 || jam_keluar < 1 || jam_keluar > 24)
    {
        printf("Jam harus antara 1 dan 24.\n");
        return 0;
    }
    

    if (jam_keluar >= jam_masuk) {
        lama_parkir = jam_keluar - jam_masuk;
    } else {
        lama_parkir = (24 - jam_masuk) + jam_keluar;
    }

    if (lama_parkir == 0) {
        lama_parkir = 1; 
    }

    total_bayar = lama_parkir * tarif_per_jam;

    printf("\n--- STRUK PARKIR ---\n");
    printf("Lama Parkir: %d jam\n", lama_parkir);
    printf("Total Bayar: Rp %d\n", total_bayar);

    return 0;
}