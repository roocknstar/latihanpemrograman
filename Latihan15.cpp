#include <stdio.h>

void cetakSlip(int id, float gaji) {
    FILE *slip = fopen("slip_gaji.txt", "w");
    if (slip != NULL) {
        fprintf(slip, "ID Pegawai: %d\nGaji Bersih: Rp %.2f\n", id, gaji);
        fclose(slip);
        printf("Slip berhasil dicetak ke slip_gaji.txt\n");
    }
}

int main() {
    int id_pegawai;
    float gaji_pokok;

    printf("Masukkan ID Pegawai: ");
    scanf("%d", &id_pegawai);
    printf("Masukkan Gaji Pokok: ");
    scanf("%f", &gaji_pokok);

    cetakSlip(id_pegawai, gaji_pokok);
    return 0;
}