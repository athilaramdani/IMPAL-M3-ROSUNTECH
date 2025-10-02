#include <stdio.h>

int main() {
    int computer_amount, peripherals;
    int business_hours, drop_pick;
    float base_fee = 0, additional_fee = 0, total_fee = 0;

    printf("Masukkan jumlah komputer: ");
    scanf("%d", &computer_amount);

    printf("Masukkan jumlah peripheral: ");
    scanf("%d", &peripherals);

    // Input waktu servis (1 = dalam jam kerja, 0 = di luar jam kerja)
    printf("Apakah service dilakukan dalam jam kerja? (1 = Ya, 0 = Tidak): ");
    scanf("%d", &business_hours);

    // Input apakah customer mau drop off dan pick up (1 = Ya, 0 = Tidak)
    printf("Apakah customer mau drop off dan pick up? (1 = Ya, 0 = Tidak): ");
    scanf("%d", &drop_pick);

    // Proses perhitungan biaya sesuai aturan
    if (computer_amount == 1 || computer_amount == 2) {
        base_fee = 50;
        additional_fee = 0;
    } else if (computer_amount >= 3 && computer_amount <= 10) {
        base_fee = 100;
        additional_fee = peripherals * 10;
    } else if (computer_amount > 10) {
        base_fee = 500;
        additional_fee = peripherals * 10;
    }

    total_fee = base_fee + additional_fee;

    // Jika servis dilakukan di luar jam kerja, base_fee menjadi double
    if (!business_hours) {
        total_fee *= 2;
    }

    // Jika customer mau drop off & pick up, total fee dibagi 2
    if (drop_pick) {
        total_fee /= 2;
    }

    // Output hasil
    printf("Total biaya servis: $%.2f\n", total_fee);

    return 0;
}
