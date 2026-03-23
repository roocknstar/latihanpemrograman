#include <stdio.h>

int main() {
    int pin, pin2, konfirmasi, kesempatan;

    while (1) {
        printf("Masukkan 4 digit PIN ATM: ");
        scanf("%d", &pin);

        if (pin >= 1000 && pin <= 9999) {
            printf("Apakah yakin untuk menyimpan PIN ini? (1 = Yakin, 0 = Ulangi): ");
            scanf("%d", &konfirmasi);

            if (konfirmasi == 1) {
                printf("PIN berhasil disimpan.\n");
                break;
            } else {
                printf("Mengulang input PIN...\n");
            }
        } else {
            printf("Error: PIN harus 4 digit.\n");
        }
    }

    kesempatan = 3;
    while (kesempatan > 0) {
        printf("Masukkan kembali PIN untuk verifikasi: ");
        scanf("%d", &pin2);

        if (pin2 == pin) {
            printf("Selamat, kamu berhasil mendaftarkan PIN ATM.\n");
            return 0;
        } else {
            kesempatan--;
            if (kesempatan > 0) {
                printf("PIN salah. Kesempatan tersisa: %d\n", kesempatan);
            }
        }
    }

    printf("Kartu Anda Diblokir.\n");
    return 0;
}