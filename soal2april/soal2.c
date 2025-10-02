#include <stdio.h>

int main() {
    // Deklarasi variabel untuk input
    int computer_amount;
    int num_peripherals = 0;
    int is_after_hours;
    int is_drop_off;

    float base_fee = 0.0;
    float additional_fee = 0.0;
    float total_fee = 0.0;

    printf("--- Kalkulator Biaya Servis Komputer ---\n\n");

    printf("Masukkan jumlah komputer: ");
    scanf("%d", &computer_amount);

    printf("Masukkan jumlah peripheral (mis: keyboard, mouse, printer): ");
    scanf("%d", &num_peripherals);

    printf("Apakah servis di luar jam kerja? (1 untuk Ya, 0 untuk Tidak): ");
    scanf("%d", &is_after_hours);

    printf("Apakah pelanggan bersedia antar-jemput sendiri? (1 untuk Ya, 0 untuk Tidak): ");
    scanf("%d", &is_drop_off);

    if (computer_amount == 1 || computer_amount == 2) {
        base_fee = 50.0;
        additional_fee = 0.0;
    } else if (computer_amount >= 3 && computer_amount <= 10) {
        base_fee = 100.0;
        additional_fee = 10.0 * num_peripherals;
    } else if (computer_amount > 10) {
        base_fee = 500.0;
        additional_fee = 10.0 * num_peripherals;
    } else {
        printf("\nJumlah komputer tidak valid. Program berhenti.\n");
        return 1;
    }

    printf("\n--- Proses Kalkulasi ---\n");
    printf("Biaya dasar awal      : $%.2f\n", base_fee);


    if (is_after_hours == 1) {
        base_fee *= 2; // base_fee digandakan
        printf("-> Biaya dasar digandakan menjadi $%.2f (servis di luar jam kerja).\n", base_fee);
    }

    if (is_drop_off == 1) {
        base_fee /= 2;
        printf("-> Biaya dasar dikurangi setengah menjadi $%.2f (antar-jemput sendiri).\n", base_fee);
    }

    total_fee = base_fee + additional_fee;

    printf("\n==========================================\n");
    printf("           Rincian Biaya Final\n");
    printf("==========================================\n");
    printf("Biaya Dasar (Base Fee)      : $%.2f\n", base_fee);
    printf("Biaya Tambahan (Peripherals): $%.2f\n", additional_fee);
    printf("------------------------------------------ +\n");
    printf("Total Biaya Servis          : $%.2f\n", total_fee);
    printf("==========================================\n");

    return 0; 
}