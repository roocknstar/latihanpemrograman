#include <stdio.h>

float asuransi(int jenisladang, float tanggungan, float luas);
void slip(char nama[], int jumlah, int jenis1, float biaya1, int jenis2, float biaya2, int jenis3, float biaya3, float totalbiaya);
int menujenis();
void ladang(int jenis);

int main() {
    char nama[100];
    int jumlah;
    float totalbiaya = 0.0;

    int jenisladang1 = 0, jenisladang2 = 0, jenisladang3 = 0;
    float asuransi1 = 0.0, asuransi2 = 0.0, asuransi3 = 0.0;

    
    printf("\n==========================\n");
    printf("PROGRAM ASURANSI PERTANIAN\n");
    printf("==========================\n");
    printf("\nMasukkan nama petani: ");
    scanf("%[^\n]", nama);
    getchar();
    
    do {
        printf("Masukkan jumlah jenis ladang (1-3): ");
        scanf("%d", &jumlah);

        if (jumlah < 1) {
            printf("Anda harus memiliki setidaknya 1 ladang.\n");
        } else if (jumlah > 3) {
            printf("Anda tidak dapat memiliki lebih dari 3 ladang.\n");
        }
    } while (jumlah < 1 || jumlah > 3);

    for (int i = 1; i <= jumlah; i++) {
        printf("\n--- Data Ladang ke-%d ---\n", i);

        int jenis = menujenis();
        float tanggungan, luas;

        printf("Masukkan tanggungan per hektar (Rp): ");
        scanf("%f", &tanggungan);
        printf("Masukkan luas ladang (hektar): ");
        scanf("%f", &luas);

        float biaya = asuransi(jenis, tanggungan, luas);
        printf("Biaya asuransi untuk ladang ini: Rp %.2f\n", biaya);

        totalbiaya += biaya;

        if (i == 1) {
            jenisladang1 = jenis;
            asuransi1 = biaya;
        } else if (i == 2) {
            jenisladang2 = jenis;
            asuransi2 = biaya;
        } else {
            jenisladang3 = jenis;
            asuransi3 = biaya;
        }
    }

    slip(nama, jumlah, jenisladang1, asuransi1, jenisladang2, asuransi2, jenisladang3, asuransi3, totalbiaya);
    return 0;
}

float asuransi(int jenisladang, float tanggungan, float luasladang) {
    float biayastandar = 0.035 * tanggungan * luasladang;
    float biayaakhir;

    switch (jenisladang) {
        case 1:
        case 2:
        case 3:
            biayaakhir = biayastandar * 1.5;
            break;
        case 4:
        case 5:
        case 6:
        case 7:
            biayaakhir = biayastandar * 2.0;
            break;
        case 8:
        default:
            biayaakhir = biayastandar;
            break;
    }

    return biayaakhir;
}

void slip(char nama[], int jumlah, int jenis1, float biaya1, int jenis2, float biaya2, int jenis3, float biaya3, float totalbiaya) {
    printf("\n==================================\n");
    printf("SLIP PEMBAYARAN ASURANSI PERTANIAN\n");
    printf("==================================\n");
    printf("Nama Petani   : %s\n", nama);
    printf("Jumlah Ladang : %d\n", jumlah);
    printf("----------------------------------\n");
    printf("Rincian Biaya per Ladang:\n");

    if (jumlah >= 1) {
        printf("1. Ladang ");
        ladang(jenis1);
        printf("\n   Biaya: Rp %.2f\n", biaya1);
    }
    if (jumlah >= 2) {
        printf("2. Ladang ");
        ladang(jenis2);
        printf("\n   Biaya: Rp %.2f\n", biaya2);
    }
    if (jumlah >= 3) {
        printf("3. Ladang ");
        ladang(jenis3);
        printf("\n   Biaya: Rp %.2f\n", biaya3);
    }

    printf("----------------------------------\n");
    printf("TOTAL ASURANSI: Rp %.2f\n", totalbiaya);
    printf("==================================\n");
}

int menujenis() {
    int pilihan;
    do {
        printf("Pilihan Jenis Ladang\n");
        printf("1. Padi\n");
        printf("2. Singkong\n");
        printf("3. Jagung\n");
        printf("4. Kacang Kedelai\n");
        printf("5. Kentang\n");
        printf("6. Bawang Merah\n");
        printf("7. Cabai\n");
        printf("8. Lainnya\n");
        printf("Masukkan pilihan (1-8): ");

        scanf(" %d", &pilihan);

        if (pilihan < 1 || pilihan > 8) {
            printf("Pilihan tidak valid. Harap pilih dari 1 hingga 8.\n");
        }
    } while (pilihan < 1 || pilihan > 8);

    return pilihan;
}

void ladang(int jenis) {
    switch (jenis) {
        case 1: printf("Padi");
        break;
        case 2: printf("Singkong");
        break;
        case 3: printf("Jagung");
        break;
        case 4: printf("Kacang Kedelai");
        break;
        case 5: printf("Kentang");
        break;
        case 6: printf("Bawang Merah");
        break;
        case 7: printf("Cabai");
        break;
        case 8: printf("Lainnya");
        break;
        default: printf("Tipe Tidak Dikenali");
        break;
    }
}