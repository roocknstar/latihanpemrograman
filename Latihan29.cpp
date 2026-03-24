#include <stdio.h>

int main() {
    float suhu[7];
    float totalSuhu = 0.0;
    float rataRata;
    float suhuDingin, suhuPanas;
    int i;

    for (i = 0; i < 7; i++) {
        printf("Masukkan suhu hari ke-%d: ", i + 1);
        scanf("%f", &suhu[i]);

        totalSuhu = totalSuhu + suhu[i];

        if (i == 0) {
            suhuDingin = suhu[i];
            suhuPanas = suhu[i];
        } else {
            if (suhu[i] > suhuPanas) {
                suhuPanas = suhu[i];
            }
            if (suhu[i] < suhuDingin) {
                suhuDingin = suhu[i];
            }
        }
    }

    rataRata = totalSuhu / 7.0;

    printf("Suhu Rata-rata   : %.2f C\n", rataRata);
    printf("Suhu Paling Panas : %.2f C\n", suhuPanas);
    printf("Suhu Paling Dingin: %.2f C\n", suhuDingin);

    return 0;
}