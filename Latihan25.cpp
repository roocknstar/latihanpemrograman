#include <stdio.h>

typedef struct {
    char nama[50];
    int jumlah;
} Item;

int main() {
    int pilihan;
    FILE *fp;
    Item barangbelanja;

    do {
        printf("\n====== List  Belanja ======\n");
        printf("1. Tambah Item Belanja\n");
        printf("2. Tampilkan Daftar Belanja\n");
        printf("3. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            printf("Masukkan nama barang: ");
            scanf("%s", barangbelanja.nama);
            printf("Masukkan jumlah: ");
            scanf("%d", &barangbelanja.jumlah);
            fp = fopen("list_belanja.txt", "a");
            
            if (fp != NULL) {
                fprintf(fp, "%s %d\n", barangbelanja.nama, barangbelanja.jumlah);
                fclose(fp);
                printf("Data berhasil disimpan!\n");
            } else {
                printf("Gagal membuka file untuk menyimpan.\n");
            }

        } else if (pilihan == 2) {
            fp = fopen("list_belanja.txt", "r");
            
            if (fp != NULL) {
                printf("\n--- Isi Daftar Belanja ---\n");
                printf("==== Barang  (Jumlah) ====\n");
                printf("--------------------------\n");

                while (fscanf(fp, "%s %d", barangbelanja.nama, &barangbelanja.jumlah) != EOF) {
                    printf("%s (%d)\n", barangbelanja.nama, barangbelanja.jumlah);
                }
                fclose(fp);
            } else {
                printf("\nAnda belum memiliki daftar belanja.\n");
            }

        } else if (pilihan == 3) {
            printf("Terima kasih!\n");
        } else {
            printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 3);

    return 0;
}