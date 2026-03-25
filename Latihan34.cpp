#include <stdio.h>

int stokRak[5]; 

char namaRak1[50];
char namaRak2[50];
char namaRak3[50];
char namaRak4[50];
char namaRak5[50];

void setupAwal();
void tampilkanMenu();
void tambahStok();
void kurangiStok();
void tampilkanLaporan();
void cetakNamaRak(int index);

int pilihRak();

int main() {
    int pilihan;

    setupAwal();

    do {
        tampilkanMenu();
        scanf("%d", &pilihan);
        
        getchar(); 

        switch (pilihan) {
            case 1:
                tambahStok();
                break;
            case 2:
                kurangiStok();
                break;
            case 3:
                tampilkanLaporan();
                break;
            case 4:
                printf("\nTerima kasih telah menggunakan aplikasi gudang.\n");
                break;
            default:
                printf("\nPilihan tidak valid. Silakan masukkan angka 1-4.\n");
                break;
        }

    } while (pilihan != 4);

    return 0;
}

void setupAwal() {
    printf("--- Selamat Datang di Aplikasi Gudang ---\n");
    printf("Silakan lakukan setup awal nama barang untuk 5 rak:\n");

    printf("Masukkan nama barang Rak 1: ");
    scanf("%[^\n]", namaRak1);
    getchar();

    printf("Masukkan nama barang Rak 2: ");
    scanf("%[^\n]", namaRak2);
    getchar();

    printf("Masukkan nama barang Rak 3: ");
    scanf("%[^\n]", namaRak3);
    getchar();

    printf("Masukkan nama barang Rak 4: ");
    scanf("%[^\n]", namaRak4);
    getchar();

    printf("Masukkan nama barang Rak 5: ");
    scanf("%[^\n]", namaRak5);
    getchar();

    for (int i = 0; i < 5; i++) {
        stokRak[i] = 0;
    }

    printf("\nSetup awal selesai. Stok semua barang diatur ke 0.\n");
}

void tampilkanMenu() {
    printf("\n--- Menu Utama Gudang ---\n");
    printf("1. Tambah Stok Barang\n");
    printf("2. Kurangi Stok Barang\n");
    printf("3. Tampilkan Laporan Stok (Histogram)\n");
    printf("4. Keluar\n");
    printf("Pilihan Anda (1-4): ");
}

void cetakNamaRak(int index) {
    switch (index) {
        case 0:
            printf("%s", namaRak1);
            break;
        case 1:
            printf("%s", namaRak2);
            break;
        case 2:
            printf("%s", namaRak3);
            break;
        case 3:
            printf("%s", namaRak4);
            break;
        case 4:
            printf("%s", namaRak5);
            break;
    }
}

int pilihRak() {
    int pilihanRak;
    printf("\n--- Pilih Rak ---\n");

    for (int i = 0; i < 5; i++) {
        printf("%d. ", i + 1);
        cetakNamaRak(i); 
        printf(" (Stok: %d)\n", stokRak[i]);
    }

    do {
        printf("Pilih Rak (1-5): ");
        scanf("%d", &pilihanRak);
        if (pilihanRak < 1 || pilihanRak > 5) { 
            printf("Input tidak valid. Harap masukkan 1-5.\n");
        }
    } while (pilihanRak < 1 || pilihanRak > 5);
    
    getchar();
    return pilihanRak - 1;
}

void tambahStok() {
    int index = pilihRak();
    int jumlah;

    printf("Masukkan jumlah yang ingin ditambahkan: ");
    scanf("%d", &jumlah);
    getchar();

    if (jumlah < 0) { 
        printf("Jumlah tidak boleh negatif. Penambahan dibatalkan.\n");
    } else {
        stokRak[index] = stokRak[index] + jumlah;
        printf("Berhasil! Stok ");
        cetakNamaRak(index);
        printf(" sekarang adalah %d.\n", stokRak[index]);
    }
}

void kurangiStok() {
    int index = pilihRak();
    int jumlah;

    printf("Masukkan jumlah yang ingin dikurangi: ");
    scanf("%d", &jumlah);
    getchar();

    if (jumlah < 0) {
        printf("Jumlah tidak boleh negatif. Pengurangan dibatalkan.\n");
    } 
    else if (stokRak[index] - jumlah < 0) { 
        printf("ERROR: Stok tidak mencukupi!\n");
        printf("Stok ");
        cetakNamaRak(index);
        printf(" saat ini hanya %d. Pengurangan dibatalkan.\n", stokRak[index]);
    } 
    else {
        stokRak[index] = stokRak[index] - jumlah; 
        printf("Berhasil! Stok ");
        cetakNamaRak(index);
        printf(" sekarang adalah %d.\n", stokRak[index]);
    }
}

void tampilkanLaporan() {
    printf("\nLaporan Stok Gudang:\n");

    for (int i = 0; i < 5; i++) {
        printf("%d. ", i + 1);
        cetakNamaRak(i);
        printf(" (%d): ", stokRak[i]);

        for (int j = 0; j < stokRak[i]; j++) {
            printf("#");
        }
        printf("\n");
    }
}