# 📌 Program Perhitungan Biaya Servis Komputer (C)

## 📝 Narasi Soal
Program ini diminta untuk dibuat dalam bahasa C dengan memperhatikan **Preconditions** dan **Postconditions** berikut:

- **Precondition 1**  
  Customer datang dengan `account-number` yang sesuai dengan data yang ada di **ACCOUNTS**, dan `status-code` dari akun tersebut bernilai `"valid"`.  

  **Postcondition 1**  
  Sistem menghasilkan sebuah **Invoice** yang berisi `account-number` dan `amount-of-sale`.

- **Precondition 2**  
  Jika **Precondition 1 gagal** dengan alasan apapun (misalnya `account-number` tidak ditemukan pada database **ACCOUNTS** atau `status-code` akun tidak sama dengan `"valid"`).  

  **Postcondition 2**  
  Sistem akan menampilkan **error message** kepada user.  

---

## 📖 Penjelasan Deskriptif

Secara garis besar, soal ini menggambarkan **alur validasi data pelanggan** sebelum sebuah transaksi servis komputer bisa diproses.  

1. **Data Akun Pelanggan (ACCOUNTS)**  
   - Sistem menyimpan sekumpulan data akun pelanggan.  
   - Setiap akun terdiri dari:
     - `account-number` → identitas unik pelanggan.
     - `status-code` → status keaktifan akun, misalnya `"valid"`, `"invalid"`, `"suspended"`.  

   Dengan adanya data ini, sistem bisa melakukan pengecekan apakah akun pelanggan **layak diproses** atau tidak.  

2. **Kedatangan Customer**  
   - Seorang customer datang dan memberikan **account-number** miliknya.  
   - Sistem kemudian mencocokkan account number tersebut dengan daftar **ACCOUNTS** yang ada di database.  

3. **Proses Validasi (Precondition)**  
   - Jika account number ditemukan **dan** statusnya `"valid"`, maka kondisi **Precondition 1** terpenuhi.  
   - Jika salah satu kondisi tidak terpenuhi (account number tidak ada, atau status bukan `"valid"`), maka kondisi **Precondition 2** berlaku.  

4. **Hasil Proses (Postcondition)**  
   - **Postcondition 1 (Sukses):**  
     Sistem membuat **Invoice** yang berisi:
     - Account number milik customer.
     - Besar biaya servis (amount-of-sale).  
     Invoice ini menjadi bukti resmi transaksi.  

   - **Postcondition 2 (Gagal):**  
     Sistem tidak memproses transaksi lebih lanjut dan menampilkan **error message** ke layar.  
     Misalnya: *"ERROR: Account tidak ditemukan"* atau *"ERROR: Status akun tidak valid"*.  

5. **Tujuan Utama Program**  
   - Menjamin hanya akun pelanggan yang **valid** yang bisa melakukan transaksi.  
   - Mencegah akun yang tidak terdaftar atau berstatus bermasalah melakukan servis.  
   - Memberikan umpan balik yang jelas kepada pengguna dalam bentuk **Invoice** atau **Error Message**.  

---

## 🗂️ Kesimpulan
Soal ini menekankan pada konsep **Precondition & Postcondition** dalam pemrograman, yaitu:

- **Precondition** memastikan syarat tertentu terpenuhi sebelum suatu proses dieksekusi.  
- **Postcondition** menjelaskan hasil atau dampak dari proses tersebut.  

Dalam konteks ini:
- Jika akun **valid**, sistem menghasilkan **Invoice** (Postcondition 1).  
- Jika akun **tidak valid atau tidak ditemukan**, sistem menghasilkan **Error Message** (Postcondition 2).  

Dengan demikian, program ini dapat dipandang sebagai contoh sederhana penerapan **validasi input dan kontrol alur** dalam sebuah sistem transaksi berbasis C.  
