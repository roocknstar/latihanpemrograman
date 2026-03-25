#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tarif_dasar = 5000;

int validasi_jenis_kendaraan(int i, char v_jenis_kendaraan[], int n_jenis_kendaraan[]) {
    int valid = 0;
    
    do {
        printf("Masukan jenis kendaraan (Mobil/Motor/Truk): ");
        scanf("%s", v_jenis_kendaraan);
            
        if (strcmp(v_jenis_kendaraan, "Mobil") == 0 || strcmp(v_jenis_kendaraan, "mobil") == 0) {
            n_jenis_kendaraan[i] = 1;
            valid = 1;
        } else if (strcmp(v_jenis_kendaraan, "Motor") == 0 || strcmp(v_jenis_kendaraan, "motor") == 0) {
            n_jenis_kendaraan[i] = 2;
            valid = 1;
        } else if (strcmp(v_jenis_kendaraan, "Truk") == 0 || strcmp(v_jenis_kendaraan, "truk") == 0) {
            n_jenis_kendaraan[i] = 3;
            valid = 1;
        } else {
            printf("Jenis kendaraan tidak valid. Silakan masukan 'Mobil', 'Motor', atau 'Truk'.\n");
        }
    } while (valid == 0);

    return n_jenis_kendaraan[i];
}

float hitung_tarif_awal(char *jenis_kendaraan) {
    float tarif_parkir_perjam = 0;

    if (strcmp(jenis_kendaraan, "Mobil") == 0 || strcmp(jenis_kendaraan, "mobil") == 0) {
        tarif_parkir_perjam = tarif_dasar;
    }
    else if (strcmp(jenis_kendaraan, "Motor") == 0 || strcmp(jenis_kendaraan, "motor") == 0) {
        tarif_parkir_perjam = tarif_dasar * 0.5;
    }
    else if (strcmp(jenis_kendaraan, "Truk") == 0 || strcmp(jenis_kendaraan, "truk") == 0) {
        tarif_parkir_perjam = tarif_dasar * 2;
    }
    else {
        printf("Jenis kendaraan tidak valid.\n");
        return -1;
    }
    
    return tarif_parkir_perjam;
}

float hitung_biaya_parkir(float tarif_parkir, int lama_parkir) {
    float total = tarif_parkir * lama_parkir;

    if (lama_parkir > 5) {
        total = total - (total * 0.10);
    }

    return total;
}

float hitung_total_biaya(float biaya_kendaraan[], int jumlah_kendaraan) {
    float total_biaya = 0;

    for (int i = 0; i < jumlah_kendaraan; i++) {
        total_biaya += biaya_kendaraan[i];
    }

    return total_biaya;
}

void cetakStrukTerminal(char nama[], int jenis[], int lama[], float biaya[], int jumlah, float total_semua) {
    char nama_kendaraan[4][10] = {"", "Mobil", "Motor", "Truk"};
    
    printf("\n========================================\n");
    printf("              STRUK PARKIR              \n");
    printf("========================================\n");
    printf("Nama Pelanggan   : %s\n", nama);
    printf("Jumlah Kendaraan : %d\n", jumlah);
    printf("----------------------------------------\n");
    
    for (int i = 0; i < jumlah; i++) {
        printf("Kendaraan %d      : %s\n", i+1, nama_kendaraan[jenis[i]]);
        printf("Lama Parkir      : %d jam\n", lama[i]);
        printf("Biaya Parkir     : Rp %.2f\n", biaya[i]);
        if (lama[i] > 5) {
            printf("*(Mendapat Diskon 10%%)\n");
        }
        printf("\n");
    }
    
    printf("----------------------------------------\n");
    printf("TOTAL BIAYA      : Rp %.2f\n", total_semua);
    printf("========================================\n");
}

void cetakStrukFile(char nama[], int jenis[], int lama[], float biaya[], int jumlah, float total_semua) {
    char nama_kendaraan[4][10] = {"", "Mobil", "Motor", "Truk"};
    
    FILE *fp = fopen("strukparkir.txt", "w");
    if (fp == NULL) {
        printf("File 'strukparkir.txt' tidak dapat dibuat!\n");
        return;
    }
    
    fprintf(fp, "========================================\n");
    fprintf(fp, "              STRUK PARKIR              \n");
    fprintf(fp, "========================================\n");
    fprintf(fp, "Nama Pelanggan   : %s\n", nama);
    fprintf(fp, "Jumlah Kendaraan : %d\n", jumlah);
    fprintf(fp, "----------------------------------------\n");
    
    for (int i = 0; i < jumlah; i++) {
        fprintf(fp, "Kendaraan %d      : %s\n", i+1, nama_kendaraan[jenis[i]]);
        fprintf(fp, "Lama Parkir      : %d jam\n", lama[i]);
        fprintf(fp, "Biaya Parkir     : Rp %.2f\n", biaya[i]);
        if (lama[i] > 5) {
            fprintf(fp, "*(Mendapat Diskon 10%%)\n");
        }
        fprintf(fp, "\n");
    }
    
    fprintf(fp, "----------------------------------------\n");
    fprintf(fp, "TOTAL BIAYA      : Rp %.2f\n", total_semua);
    fprintf(fp, "========================================\n");
    
    fclose(fp);
}

int main() {
    char nama[50];
    int jumlah_kendaraan;
    char v_jenis_kendaraan[20];
    int n_jenis_kendaraan[3]; 
    int lama_parkir[3];
    float biaya_kendaraan[3];
    float total_keseluruhan = 0;

    printf("Masukan nama Anda: ");
    scanf("%s", nama);

    do {
        printf("Masukan jumlah kendaraan (maksimal 3): ");
        scanf("%d", &jumlah_kendaraan);

        if (jumlah_kendaraan < 1 || jumlah_kendaraan > 3) {
            printf("Jumlah kendaraan tidak valid. Silakan masukan antara 1 hingga 3 kendaraan.\n");
        }
    } while(jumlah_kendaraan < 1 || jumlah_kendaraan > 3);

    for (int i = 0; i < jumlah_kendaraan; i++) {
        printf("\nKendaraan %d:\n", i + 1);

        validasi_jenis_kendaraan(i, v_jenis_kendaraan, n_jenis_kendaraan);

        printf("Masukan lama parkir (dalam jam): ");
        scanf("%d", &lama_parkir[i]);
        
        float tarif_perjam = hitung_tarif_awal(v_jenis_kendaraan);
        biaya_kendaraan[i] = hitung_biaya_parkir(tarif_perjam, lama_parkir[i]);
    }

    total_keseluruhan = hitung_total_biaya(biaya_kendaraan, jumlah_kendaraan);
    
    cetakStrukTerminal(nama, n_jenis_kendaraan, lama_parkir, biaya_kendaraan, jumlah_kendaraan, total_keseluruhan);
    cetakStrukFile(nama, n_jenis_kendaraan, lama_parkir, biaya_kendaraan, jumlah_kendaraan, total_keseluruhan);
    
    return 0;
}