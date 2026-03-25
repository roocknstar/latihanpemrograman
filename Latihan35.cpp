#include <stdio.h>
#include <string.h>

struct Menu {
    char kodeMenu[10];
    char namaMenu[50];
    int  harga;
    int  stok;
};

struct Menu dataMenu[100];
int jumlahMenu = 0;
char* NAMA_FILE = "warung_nasgor.txt";

void bersihkanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void bacaDataDariFile() {
    FILE* fileInput = fopen(NAMA_FILE, "r");
    
    if (fileInput == NULL) {
        printf("File database %s tidak ditemukan.\n", NAMA_FILE);
        return;
    }

    while (fscanf(fileInput, "%s %s %d %d\n",
                  dataMenu[jumlahMenu].kodeMenu,
                  dataMenu[jumlahMenu].namaMenu,
                  &dataMenu[jumlahMenu].harga,
                  &dataMenu[jumlahMenu].stok) == 4) {
        
        jumlahMenu++;
        
        if (jumlahMenu >= 100) {
            break;
        }
    }
    fclose(fileInput);
    printf("Berhasil memuat %d data menu.\n", jumlahMenu);
}

void simpanDataKeFile() {
    FILE* fileOutput = fopen(NAMA_FILE, "w");
    if (fileOutput == NULL) {
        printf("Error: Gagal menyimpan file.\n");
        return;
    }
    
    for (int i = 0; i < jumlahMenu; i++) {
        fprintf(fileOutput, "%s %s %d %d\n",
                dataMenu[i].kodeMenu,
                dataMenu[i].namaMenu,
                dataMenu[i].harga,
                dataMenu[i].stok);
    }
    fclose(fileOutput);
    printf("Data berhasil disimpan.\n");
}

int loginAdmin() {
    char username[50];
    char password[50];
    printf("--- LOGIN ADMIN ---\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    bersihkanBuffer();

    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        printf("Login berhasil!\n");
        return 1;
    } else {
        printf("Login gagal.\n");
        return 0;
    }
}

void tampilkanMenuUtama() {
    printf("\n--- MENU UTAMA DATABASE ---\n");
    printf("1. Tambah Menu Baru\n");
    printf("2. Tampilkan Semua Menu\n");
    printf("3. Cari Menu (Kode)\n");
    printf("4. Ubah Stok Menu\n");
    printf("5. Hapus Menu\n");
    printf("6. Simpan & Keluar\n");
    printf("Pilihan Anda (1-6): ");
}

void tambahMenuBaru() {
    if (jumlahMenu >= 100) {
        printf("Database penuh!\n");
        return;
    }
    printf("\n--- TAMBAH MENU BARU ---\n");

    printf("Kode Menu: ");
    scanf("%s", dataMenu[jumlahMenu].kodeMenu);
    printf("Nama Menu (Ganti spasi dgn '_'): ");
    scanf("%s", dataMenu[jumlahMenu].namaMenu);
    printf("Harga Menu: ");
    scanf("%d", &dataMenu[jumlahMenu].harga);
    printf("Stok Awal: ");
    scanf("%d", &dataMenu[jumlahMenu].stok);
    bersihkanBuffer();
    
    printf("Menu '%s' berhasil ditambahkan!\n", dataMenu[jumlahMenu].namaMenu);
    
    jumlahMenu++;
}

void tampilkanSemuaMenu() {
    printf("\n--- DAFTAR SEMUA MENU (%d menu) ---\n", jumlahMenu);
    if (jumlahMenu == 0) {
        printf("Database masih kosong.\n");
        return;
    }
    
    for (int i = 0; i < jumlahMenu; i++) {
        printf("--------------------\n");
        printf("Kode    : %s\n", dataMenu[i].kodeMenu);
        printf("Nama    : %s\n", dataMenu[i].namaMenu);
        printf("Harga   : Rp %d\n", dataMenu[i].harga);
        printf("Stok    : %d porsi\n", dataMenu[i].stok);
    }
}

void cariMenu() {
    char kodeDicari[10];
    printf("\n--- CARI MENU ---\n");
    printf("Masukkan Kode Menu: ");
    scanf("%s", kodeDicari);
    bersihkanBuffer();

    int ditemukan = 0;
    
    for (int i = 0; i < jumlahMenu; i++) {
        if (strcmp(dataMenu[i].kodeMenu, kodeDicari) == 0) {
            printf("Menu ditemukan:\n");
            printf("Kode    : %s\n", dataMenu[i].kodeMenu);
            printf("Nama    : %s\n", dataMenu[i].namaMenu);
            printf("Harga   : Rp %d\n", dataMenu[i].harga);
            printf("Stok    : %d porsi\n", dataMenu[i].stok);
            ditemukan = 1;
            break;
        }
    }
    
    if (ditemukan == 0) {
        printf("Menu kode '%s' tidak ditemukan.\n", kodeDicari);
    }
}

void ubahStokMenu() {
    char kodeDicari[10];
    printf("\n--- UBAH STOK MENU ---\n");
    printf("Masukkan Kode Menu: ");
    scanf("%s", kodeDicari);

    int indexMenu = -1;
    for (int i = 0; i < jumlahMenu; i++) {
        if (strcmp(dataMenu[i].kodeMenu, kodeDicari) == 0) {
            indexMenu = i;
            break;
        }
    }

    if (indexMenu != -1) {
        printf("Menu ditemukan: %s (Stok: %d)\n", dataMenu[indexMenu].namaMenu, dataMenu[indexMenu].stok);
        
        int stokBaru;
        printf("Masukkan jumlah stok baru: ");
        scanf("%d", &stokBaru);
        bersihkanBuffer();
        
        dataMenu[indexMenu].stok = stokBaru;
        printf("Stok berhasil diperbarui.\n");
    } else {
        printf("Menu kode '%s' tidak ditemukan.\n", kodeDicari);
    }
}

void hapusMenu() {
    char kodeDicari[10];
    printf("\n--- HAPUS MENU ---\n");
    printf("Masukkan Kode Menu: ");
    scanf("%s", kodeDicari);
    bersihkanBuffer();

    int indexHapus = -1;
    for (int i = 0; i < jumlahMenu; i++) {
        if (strcmp(dataMenu[i].kodeMenu, kodeDicari) == 0) {
            indexHapus = i;
            break;
        }
    }

    if (indexHapus != -1) {
        for (int i = indexHapus; i < jumlahMenu - 1; i++) {
            dataMenu[i] = dataMenu[i + 1];
        }

        jumlahMenu--; 
        printf("Menu '%s' berhasil dihapus.\n", kodeDicari);
    } else {
        printf("Menu kode '%s' tidak ditemukan.\n", kodeDicari);
    }
}

int main() {
    printf("Memulai Sistem Database...\n");
    
    if (loginAdmin() == 0) {
        printf("Program akan berhenti.\n");
        return 1;
    }

    bacaDataDariFile();

    int pilihanMenu = 0; 
    
    do {
        tampilkanMenuUtama();
        
        int hasilScan = scanf("%d", &pilihanMenu);
        bersihkanBuffer();
        
        if (hasilScan != 1) {
            printf("Input tidak valid. Masukkan angka (1-6).\n");
            continue;
        }

        switch (pilihanMenu) {
            case 1:
                tambahMenuBaru();
                break;
            case 2:
                tampilkanSemuaMenu();
                break;
            case 3:
                cariMenu();
                break;
            case 4:
                ubahStokMenu();
                break;
            case 5:
                hapusMenu();
                break;
            case 6:
                printf("Menyimpan data...\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih 1-6.\n");
        }

    } while (pilihanMenu != 6);

    simpanDataKeFile();
    printf("Terima kasih!\n");
    return 0;
}