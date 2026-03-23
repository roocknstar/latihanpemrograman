#include <stdio.h>

int main() {
    int angka[5];
    int nilai_maksimal;
    int nilai_maksimal_file = -999999;
    int i;
    FILE *fp;

    for (i = 0; i < 5; i++) {
        printf("Masukkan bilangan ke-%d: ", i + 1);
        scanf("%d", &angka[i]);
    }

    printf("\nAngka yang dimasukkan: ");
    nilai_maksimal = angka[0];
    for (i = 0; i < 5; i++) {
        printf("%d ", angka[i]);
        
        if (angka[i] > nilai_maksimal) {
            nilai_maksimal = angka[i];
        }
    }
    printf("\nNilai Maksimal anda masukkan: %d\n", nilai_maksimal);
    fp = fopen("MaxValue.txt", "r");
    
    if (fp != NULL) {
        fscanf(fp, "%d", &nilai_maksimal_file);
        printf("Nilai maksimal di file saat ini: %d\n", nilai_maksimal_file);
        fclose(fp);
    } else {
        printf("File MaxValue.txt masih kosong.\n");
    }

    if (nilai_maksimal > nilai_maksimal_file) {
        printf("Selamat! Nilai anda (%d) lebih besar dari nilai record file (%d).\n", nilai_maksimal, nilai_maksimal_file);
        fp = fopen("MaxValue.txt", "w");
        
        if (fp != NULL) {
            fprintf(fp, "%d", nilai_maksimal);
            fclose(fp);
            printf("File berhasil diupdate.\n");
        } else {
            printf("Gagal menulis ke file.\n");
        }
    } else {
        printf("Nilai anda tidak lebih besar dari record di file. File tidak berubah.\n");
    }

    return 0;
}