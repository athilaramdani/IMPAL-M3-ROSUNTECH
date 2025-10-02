Penjelasan secara deskriptif

Bilangan Bulat
Program ini digunakan untuk menentukan jenis segitiga berdasarkan tiga bilangan bulat sebagai panjang sisi-sisinya.

Alur Kerja:
1. Program meminta input tiga sisi segitiga yaitu a, b, dan c.
2. Program mengecek apakah ada sisi yang kurang dari atau sama dengan nol. Jika ada maka segitiga tidak dapat dibangun.
3. Program menentukan sisi terbesar di antara ketiga sisi. Misalnya max adalah sisi terbesar. Jika max lebih besar atau sama dengan jumlah dua sisi lainnya, maka segitiga tidak dapat dibangun.
4. Jika segitiga valid maka program melakukan pengecekan jenis segitiga.
- Jika a sama dengan b dan b sama dengan c maka segitiga sama sisi (Equilateral).
- Jika ada dua sisi yang sama maka segitiga sama kaki (Isosceles).
- Jika berlaku teorema Pythagoras yaitu kuadrat sisi terbesar sama dengan jumlah kuadrat dua sisi lainnya maka segitiga siku-siku (Right Triangle).
- Jika tidak memenuhi kondisi di atas maka segitiga bebas (Scalene).

Contoh Hasil
Input 3 4 5 menghasilkan segitiga siku-siku.
Input 5 5 8 menghasilkan segitiga sama kaki.
Input 3 3 3 menghasilkan segitiga sama sisi.
Input 1 2 3 menghasilkan bukan segitiga.


Bilangan Pecahan dengan Ketelitian 1 Persen
Program ini digunakan untuk menentukan jenis segitiga jika input berupa bilangan pecahan. Perbandingan tidak dilakukan secara persis, melainkan dengan toleransi 1 persen. 
Dua bilangan dianggap sama jika selisihnya tidak lebih dari 1 persen dari nilai yang lebih besar.

Fungsi Pembantu
Program menggunakan fungsi hampir_sama(x, y) yang mengembalikan benar jika x dan y dianggap sama dalam toleransi 1 persen.
Fungsi ini menggunakan fabs untuk mengambil nilai mutlak dan fmax untuk mengambil nilai terbesar dari dua angka.

Alur Kerja
1. Program meminta input tiga sisi segitiga yaitu a, b, dan c bertipe double.
2. Program mengecek apakah ada sisi yang kurang dari atau sama dengan nol. Jika ada maka segitiga tidak dapat dibangun.
3. Program menentukan sisi terbesar dari ketiga sisi. Jika sisi terbesar lebih besar atau sama dengan jumlah dua sisi lainnya maka segitiga tidak dapat dibangun.
4. Jika segitiga valid maka program melakukan pengecekan jenis segitiga menggunakan perbandingan dengan toleransi 1 persen.
- Jika a hampir sama dengan b dan b hampir sama dengan c maka segitiga sama sisi (Equilateral).
- Jika ada dua sisi yang hampir sama maka segitiga sama kaki (Isosceles).
- Jika kuadrat sisi terbesar hampir sama dengan jumlah kuadrat dua sisi lainnya maka segitiga siku-siku (Right Triangle).
- Jika tidak memenuhi kondisi di atas maka segitiga bebas (Scalene).

Contoh Hasil
Input 3 4 5 menghasilkan segitiga siku-siku.
Input 2.0 2.01 2.0 menghasilkan segitiga sama kaki karena selisih sisi hanya 0.5 persen.
Input 5.0 5.05 5.0 menghasilkan segitiga sama sisi karena perbedaan masih dalam toleransi 1 persen.
Input 1.0 2.0 3.0 menghasilkan bukan segitiga.
