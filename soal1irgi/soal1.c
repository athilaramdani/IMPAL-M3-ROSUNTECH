// soal1irgi\soal1.c
#include <stdio.h>

int main() {
    int a, b, c;
    printf("Masukkan tiga sisi segitiga (a b c): ");
    scanf("%d %d %d", &a, &b, &c);
    //Cek sisi valid (> 0)
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Bukan segitiga (ada sisi <= 0)\n");
        return 0;
    }
    //Cari sisi terbesar
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    int sum = a + b + c;
    int sum_others = sum - max;
    //Cek syarat segitiga (jumlah dua sisi > sisi terbesar)
    if (max >= sum_others) {
        printf("Bukan segitiga (sisi terbesar >= jumlah dua sisi lainnya)\n");
        return 0;
    }
    //Cek segitiga sama sisi
    if (a == b && b == c) {
        printf("Segitiga Sama Sisi (Equilateral)\n");
    }
    //Cek segitiga sama kaki
    else if (a == b || b == c || a == c) {
        printf("Segitiga Sama Kaki (Isosceles)\n");
    }
    // Cek segitiga siku-siku
    else if (max*max == (a*a + b*b + c*c - max*max)) {
        printf("Segitiga Siku-Siku (Right Triangle)\n");
    }
    //Jika tidak termasuk kategori di atas
    else {
        printf("Segitiga Bebas (Scalene)\n");
    }
    return 0;
}
