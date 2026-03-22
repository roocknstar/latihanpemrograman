#include <stdio.h>

int main() {
    int menu, total = 0;
    FILE *nota;

    do {
        printf("1. Ayam Goreng + Nasi (Rp 25000)\n2. Ayam Goreng (Rp 20000)\n3. Es Teh (Rp 5000)\n0. Selesai\nPilih: ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            total += 25000;
            break;
        case 2:
            total += 20000;
            break;
        case 3:
            total += 5000;
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
        }

    } while (menu != 0);

    nota = fopen("nota_restoran.txt", "w");
    fprintf(nota, "=== NOTA RESTORAN ===\nTotal Belanja: Rp %d\n", total);
    fclose(nota);

    printf("Pesanan selesai. Total Rp %d disimpan ke file.\n", total);
    return 0;
}