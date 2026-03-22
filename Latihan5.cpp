#include <stdio.h>

void tampilkanMenu() {
    printf("\n--- Perhitungan Sederhana ---\n");
    printf("1. Tambah\n2. Kurang\n3. Kali\n4. Bagi\n5. Keluar\n");
}

int main() {
    int pilihan;
    int a, b;

    do {
        tampilkanMenu();
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        if (pilihan == 1 || pilihan == 2 || pilihan == 3 || pilihan == 4) {
            printf("Masukkan angka pertama: ");
            scanf("%d", &a);
            printf("Masukkan angka kedua: ");
            scanf("%d", &b);

            if (pilihan == 1) {
                printf("Hasil: %d\n", a + b);
            } else if (pilihan == 2) {
                printf("Hasil: %d\n", a - b);
            } else if (pilihan == 3) {
                printf("Hasil: %d\n", a * b);
            } else {
                if (b != 0) {
                    printf("Hasil: %d\n", a / b);
                } else {
                    printf("Error: Pembagian oleh nol tidak diperbolehkan.\n");
                }
            }
        }
    } while (pilihan != 5);

    return 0;
}