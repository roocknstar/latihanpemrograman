#include <stdio.h>

int main(){
    int hasil;
    for (int i = 1; i <= 8; i+=i){
        hasil = i * i;
        printf("%d x %d = %d\n", i, i, hasil);
    }
}