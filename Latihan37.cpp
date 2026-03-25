#include <stdio.h>

int tampilanJumlahMahasiswa() {
    int jumlahMahasiswa;
    printf("Masukan jumlah mahasiswa: ");
    scanf("%d", &jumlahMahasiswa);
    return jumlahMahasiswa;
}

int main() {
    int jumlahMahasiswa, i;
    int nilaiTugas, nilaiUTS, nilaiUAS;
    int predikatA = 0, predikatB = 0, predikatC = 0, predikatD = 0;
    float nilaiAkhir, totalNilai = 0.0, nilaiRemedial, nilaiRata, nilaiTinggi = 0.0, nilaiRendah = 100.0;
    char predikat;

    jumlahMahasiswa = tampilanJumlahMahasiswa();

    if (jumlahMahasiswa <= 0 || jumlahMahasiswa > 10) {
        printf("Jumlah mahasiswa harus antara 1-10!\n");
        jumlahMahasiswa = tampilanJumlahMahasiswa();
    }

    for (i = 1; i <= jumlahMahasiswa; i++) {
        printf("\nMahasiswa ke-%d\n", i);
        
        do {
            printf("Masukan nilai Tugas : ");
            scanf("%d", &nilaiTugas);
            if (nilaiTugas < 1 || nilaiTugas > 100) { 
                printf("Nilai yang dimasukkan harus antara 1-100!\n");
            }
        } while (nilaiTugas < 1 || nilaiTugas > 100);

        do {
            printf("Nilai UTS   (1-100): "); 
            scanf("%d", &nilaiUTS);
            if (nilaiUTS < 1 || nilaiUTS > 100) {
                printf("Nilai yang dimasukkan harus antara 1-100!\n"); 
            }
        } while (nilaiUTS < 1 || nilaiUTS > 100);

        do {
            printf("Nilai UAS   (1-100): "); 
            scanf("%d", &nilaiUAS);
            if (nilaiUAS < 1 || nilaiUAS > 100) {
                printf("Nilai yang dimasukkan harus antara 1-100!\n");
            }
        } while (nilaiUAS < 1 || nilaiUAS > 100);

        nilaiAkhir = (0.3 * nilaiTugas) + (0.3 * nilaiUTS) + (0.4 * nilaiUAS);

        if (nilaiAkhir < 60) {
            printf("Mahasiswa harus melakukan remedial!\n");
            do {
                printf("Masukan nilai Remedial: "); 
                scanf("%f", &nilaiRemedial);
                if (nilaiRemedial < 1 || nilaiRemedial > 100) {
                    printf("Nilai yang dimasukkan harus antara 1-100!\n");
                }
            } while (nilaiRemedial < 1 || nilaiRemedial > 100);

            if (nilaiRemedial > nilaiAkhir) {
                nilaiAkhir = nilaiRemedial;
            }
        }

        if (nilaiAkhir >= 80) {
            predikat = 'A';
            predikatA++;
        } else if (nilaiAkhir >= 70) {
            predikat = 'B';
            predikatB++;
        } else if (nilaiAkhir >= 60) {
            predikat = 'C';
            predikatC++;
        } else {
            predikat = 'D';
            predikatD++;
        }

        printf("Nilai akhir         : %.2f\n", nilaiAkhir);
        printf("Predikat            : %c\n", predikat);

        totalNilai += nilaiAkhir;

        if (nilaiAkhir > nilaiTinggi) {
            nilaiTinggi = nilaiAkhir;
        }

        if (nilaiAkhir < nilaiRendah) {
            nilaiRendah = nilaiAkhir;
        }
    }

    nilaiRata = totalNilai / jumlahMahasiswa;

    printf("Nilai rata-rata kelas               : %.2f\n", nilaiRata);
    printf("Jumlah Mahasiswa mendapat predikat A: %d mahasiswa\n", predikatA);
    printf("Jumlah Mahasiswa mendapat predikat B: %d mahasiswa\n", predikatB);
    printf("Jumlah Mahasiswa mendapat predikat C: %d mahasiswa\n", predikatC);
    printf("Jumlah Mahasiswa mendapat predikat D: %d mahasiswa\n", predikatD);
    printf("Nilai akhir tertinggi               : %.2f\n", nilaiTinggi);
    printf("Nilai akhir terendah                : %.2f\n", nilaiRendah);

    return 0;
}