#include <stdio.h>
#include <math.h>
#define TOL 0.01   //toleransi 1% (0.01)

//Fungsi untuk cek apakah dua angka dianggap sama dengan toleransi 1%
int hampir_sama(double x, double y) {
    double max_xy = fmax(fabs(x), fabs(y));
    if (max_xy < 1e-12) return 1; //kalau keduanya mendekati nol, anggap sama
    return fabs(x - y) <= TOL * max_xy;
}
int main() {
    double a, b, c;
    printf("Masukkan tiga sisi segitiga (a b c): ");
    scanf("%lf %lf %lf", &a, &b, &c);
    //Cek validitas sisi (> 0)
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Tidak ada segitiga dapat dibangun (ada sisi <= 0)\n");
        return 0;
    }
    //Cari sisi terbesar
    double max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    double jumlah = a + b + c;
    double jumlah_dua_lain = jumlah - max;
    //Cek syarat segitiga
    if (max >= jumlah_dua_lain) {
        printf("Tidak ada segitiga dapat dibangun (sisi terbesar >= jumlah dua sisi lainnya)\n");
        return 0;
    }
    //Cek segitiga sama sisi
    if (hampir_sama(a,b) && hampir_sama(b,c)) {
        printf("Segitiga Sama Sisi (Equilateral)\n");
    }
    //Cek segitiga sama kaki
    else if (hampir_sama(a,b) || hampir_sama(b,c) || hampir_sama(a,c)) {
        printf("Segitiga Sama Kaki (Isosceles)\n");
    }
    //Cek segitiga siku-siku
    else if (hampir_sama(max*max, (a*a + b*b + c*c - max*max))) {
        printf("Segitiga Siku-Siku (Right Triangle)\n");
    }
    //Kalau tidak masuk kategori di atas → segitiga bebas
    else {
        printf("Segitiga Bebas (Scalene)\n");
    }
    return 0;
}
