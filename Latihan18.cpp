#include <stdio.h>
#include <string.h>

typedef struct{
    char nama_menu[50];
    int harga;
} Menu;

typedef struct{
    char nama_pegawai[50];
    int gaji;
} Pegawai;

void tampilMenu(Menu m);
void tampilPegawai(Pegawai p);

int main(){
    int pilihan;
    printf("Pilih tipe data yang ingin ditampilkan:\n");
    printf("1. Menu Makanan\n");
    printf("2. Data Pegawai\n");
    printf("3. Keluar\n");
    printf("Masukkan pilihan Anda (1-3): ");
    scanf("%d", &pilihan);

    switch(pilihan){
        case 1: {
            Menu menu_01;
            strcpy(menu_01.nama_menu, "Nasi Goreng");
            menu_01.harga = 15000;

            Menu menu_02;
            strcpy(menu_02.nama_menu, "Mie Goreng");
            menu_02.harga = 12000;

            Menu menu_03;
            strcpy(menu_03.nama_menu, "Ayam Bakar");
            menu_03.harga = 20000;

            tampilMenu(menu_01);
            tampilMenu(menu_02);
            tampilMenu(menu_03);
            break;
        }
        case 2: {
            Pegawai pegawai_01;
            strcpy(pegawai_01.nama_pegawai, "Budi Santoso");
            pegawai_01.gaji = 3000000;

            Pegawai pegawai_02;
            strcpy(pegawai_02.nama_pegawai, "Siti Aminah");
            pegawai_02.gaji = 2800000;

            Pegawai pegawai_03;
            strcpy(pegawai_03.nama_pegawai, "Joko Widodo");
            pegawai_03.gaji = 3500000;

            tampilPegawai(pegawai_01);
            tampilPegawai(pegawai_02);
            tampilPegawai(pegawai_03);
            break;
        }
        case 3: {
            printf("Keluar dari program.\n");
            break;
        }
        default:
            printf("Pilihan tidak valid.\n");
    }
}

void tampilMenu(Menu m){
    printf("Menu: %s\n", m.nama_menu);
    printf("Harga: %d\n", m.harga);
}

void tampilPegawai(Pegawai p){
    printf("Pegawai: %s\n", p.nama_pegawai);
    printf("Gaji: %d\n", p.gaji);
}