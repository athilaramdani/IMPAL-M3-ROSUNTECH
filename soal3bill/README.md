# SOAL 3 – Implementasi Pre/Post Conditions (C)

## 📌 Deskripsi Soal

Program ini adalah **sistem transaksi pelanggan untuk layanan servis komputer**.  
Dibuat dengan bahasa **C** untuk mensimulasikan logika **Precondition & Postcondition** berikut:

- **Precondition 1**  
  Jika `account-number` ditemukan dalam database **dan** statusnya `"valid"`, maka program akan menghasilkan **Invoice**.  
  - **Postcondition 1** → Invoice dicetak ke layar.  

- **Precondition 2**  
  Jika akun **tidak ditemukan** atau statusnya bukan `"valid"`, maka transaksi gagal.  
  - **Postcondition 2** → Program menampilkan **error message**.  

---

## 📊 Flowchart

```mermaid
flowchart TD
    Start([Mulai]) --> Init[Inisialisasi Akun:<br/>ACC001-ACC005]
    Init --> Display[Tampilkan<br/>Daftar Akun]
    Display --> Input[Input Account Number<br/>& Amount of Sale]
    
    Input --> CheckExit{Input = 'exit'?}
    CheckExit -->|Ya| End([Selesai])
    
    CheckExit -->|Tidak| CheckAmount{Amount >= 0?}
    CheckAmount -->|Tidak| Error1[ERROR: Amount negatif]
    
    CheckAmount -->|Ya| FindAccount[Cari akun di database]
    FindAccount --> CheckFound{Akun<br/>ditemukan?}
    
    CheckFound -->|Tidak| Error2[ERROR: Account not found]
    CheckFound -->|Ya| CheckStatus{Status<br/>= 'valid'?}
    
    CheckStatus -->|Tidak| Error3[ERROR: Status bukan valid]
    CheckStatus -->|Ya| CreateInvoice[Buat Invoice]
    
    CreateInvoice --> PrintInvoice[Cetak Invoice:<br/>Account Number<br/>Amount of Sale]
    
    Error1 --> Continue{Lanjut?}
    Error2 --> Continue
    Error3 --> Continue
    PrintInvoice --> Continue
    
    Continue -->|Ya| Input
    Continue -->|Tidak| End
```

---

## ⚙️ Cara Compile & Run

**Compile:**
```bash
gcc soal3.c -o soal3
```

**Run:**
```bash
./soal3
```

---

## 📖 Struktur Program

### Struct yang Digunakan

```c
typedef struct {
    char accountNumber[20];
    char statusCode[20];
} Account;

typedef struct {
    char accountNumber[20];
    double amountOfSale;
} Invoice;
```

### Fungsi Utama

| Fungsi | Deskripsi |
|--------|-----------|
| `initAccounts()` | Mengisi data awal (database akun) dengan beberapa account number & status |
| `findAccount()` | Mencari akun berdasarkan nomor akun |
| `isValidStatus()` | Mengecek apakah status akun adalah "valid" |
| `printInvoice()` | Menampilkan invoice dengan format rapi |
| `process()` | Fungsi utama untuk menjalankan logika pre/post condition: validasi akun, cek status, dan buat invoice jika valid |

---

## 🖥️ Contoh Output

### 1. ✅ Precondition 1 terpenuhi

**Input:**
```
Masukkan Account Number: ACC001
Masukkan Amount of Sale: $150.50
```

**Output:**
```
Processing transaction for account: ACC001

=== INVOICE ===
Account Number: ACC001
Amount of Sale: $150.50
===============
```

### 2. ❌ Account tidak ditemukan

**Input:**
```
Masukkan Account Number: ACC999
Masukkan Amount of Sale: $100
```

**Output:**
```
Processing transaction for account: ACC999
ERROR: Account number 'ACC999' not found in system.
```

### 3. ❌ Status account bukan valid

**Input:**
```
Masukkan Account Number: ACC003
Masukkan Amount of Sale: $50
```

**Output:**
```
Processing transaction for account: ACC003
ERROR: Account 'ACC003' status is 'invalid'. Only 'valid' accounts can proceed.
```

### 4. ❌ Amount negatif

**Input:**
```
Masukkan Account Number: ACC004
Masukkan Amount of Sale: $-10
```

**Output:**
```
ERROR: Amount of sale tidak boleh negatif.
```

### 5. 🔄 Menu Interaktif

**Tampilan Awal:**
```
=== SISTEM TRANSAKSI PELANGGAN ===

Daftar Akun yang Tersedia:
- ACC001 (Status: valid)
- ACC002 (Status: valid)
- ACC003 (Status: invalid)
- ACC004 (Status: valid)
- ACC005 (Status: suspended)

--- Menu Transaksi ---
Masukkan Account Number (atau 'exit' untuk keluar): 
```

---

## 📊 Daftar Akun Default

Program otomatis menginisialisasi 5 akun:

| Account Number | Status | Hasil Transaksi |
|---------------|--------|-----------------|
| ACC001 | ✅ valid | Invoice berhasil |
| ACC002 | ✅ valid | Invoice berhasil |
| ACC003 | ❌ invalid | Error message |
| ACC004 | ✅ valid | Invoice berhasil |
| ACC005 | ⚠️ suspended | Error message |

---

## ✅ Kesesuaian dengan Soal

### Precondition 1 & Postcondition 1
1. ✅ Akun ditemukan di sistem (`findAccount()` return != NULL)
2. ✅ Status akun = "valid" (`strcmp(statusCode, "valid") == 0`)
3. ✅ **Hasil:** Invoice dicetak dengan account number dan amount of sale

### Precondition 2 & Postcondition 2
1. ❌ Akun tidak ditemukan **ATAU**
2. ❌ Status ≠ "valid" (invalid, suspended, dll)
3. ✅ **Hasil:** Error message ditampilkan

---

## 🎯 Fitur Tambahan

- ✅ Database Akun Simulasi : Terdapat 5 akun dengan status berbeda (valid, invalid, suspended).
- ✅ Menu Transaksi Interaktif: User bisa melakukan transaksi berkali-kali tanpa perlu restart program.
- ✅ Validasi Input : Amount tidak boleh negatif dan input account number tidak boleh kosong.
- ✅ Invoice dengan Format yang Rapi

**Dibuat oleh: Bill Sembiring**  
**Bahasa: C**  
**Tugas: PSPEC - DPPL**
