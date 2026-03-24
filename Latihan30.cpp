#include <stdio.h>

int main(){
    int panjang, lebar, tinggi;
    float volume, luasPermukaan;

    printf("Masukan panjang: ");
    scanf("%d", &panjang);
    printf("Masukan lebar: ");
    scanf("%d", &lebar);
    printf("Masukan tinggi: ");
    scanf("%d", &tinggi);

    volume = panjang * lebar * tinggi;
    luasPermukaan = 2 * (panjang * lebar + panjang * tinggi + lebar * tinggi);

    printf("Volume balok: %.2f\n", volume);
    printf("Luas permukaan balok: %.2f\n", luasPermukaan);

    return 0;
}