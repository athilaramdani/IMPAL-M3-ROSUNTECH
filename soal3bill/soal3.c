#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 5
#define STATUS_VALID "valid"

typedef struct {
    char accountNumber[20];
    char statusCode[20];
} Account;

typedef struct {
    char accountNumber[20];
    double amountOfSale;
} Invoice;

void initAccounts(Account accounts[]) {
    strcpy(accounts[0].accountNumber, "ACC001");
    strcpy(accounts[0].statusCode, "valid");

    strcpy(accounts[1].accountNumber, "ACC002");
    strcpy(accounts[1].statusCode, "valid");

    strcpy(accounts[2].accountNumber, "ACC003");
    strcpy(accounts[2].statusCode, "invalid");

    strcpy(accounts[3].accountNumber, "ACC004");
    strcpy(accounts[3].statusCode, "valid");

    strcpy(accounts[4].accountNumber, "ACC005");
    strcpy(accounts[4].statusCode, "suspended");
}

Account* findAccount(Account accounts[], int n, const char *accountNumber) {
    for (int i = 0; i < n; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            return &accounts[i];
        }
    }
    return NULL;
}

int isValidStatus(const char *status) {
    return (strcmp(status, STATUS_VALID) == 0);
}

void printInvoice(Invoice invoice) {
    printf("\n=== INVOICE ===\n");
    printf("Account Number : %s\n", invoice.accountNumber);
    printf("Amount of Sale : $%.2f\n", invoice.amountOfSale);
    printf("=================\n\n");
}

int process(Account accounts[], int n, const char *accountNumber, double amount, Invoice *invoice) {
    if (accountNumber == NULL || strlen(accountNumber) == 0) {
        printf("ERROR: account-number tidak boleh kosong.\n");
        return 0;
    }
    if (amount < 0) {
        printf("ERROR: amount-of-sale harus >= 0.\n");
        return 0;
    }

    Account *acc = findAccount(accounts, n, accountNumber);
    if (acc == NULL) {
        printf("ERROR: Account number '%s' not found in system.\n", accountNumber);
        return 0;
    }
    if (!isValidStatus(acc->statusCode)) {
        printf("ERROR: Account '%s' status is '%s'. Only 'valid' accounts can proceed.\n",
               acc->accountNumber, acc->statusCode);
        return 0;
    }

    strcpy(invoice->accountNumber, acc->accountNumber);
    invoice->amountOfSale = amount;
    return 1;
}

int main() {
    Account accounts[MAX_ACCOUNTS];
    initAccounts(accounts);

    printf("=== SISTEM TRANSAKSI PELANGGAN ===\n");
    printf("\nDaftar Akun yang Tersedia:\n");
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        printf("- %s (Status: %s)\n", accounts[i].accountNumber, accounts[i].statusCode);
    }

    char input[50];
    while (1) {
        printf("\n--- Menu Transaksi ---\n");
        printf("Masukkan Account Number (atau 'exit' untuk keluar): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // hapus newline

        if (strcasecmp(input, "exit") == 0) {
            printf("Terima kasih telah menggunakan sistem ini.\n");
            break;
        }

        char amountStr[50];
        printf("Masukkan Amount of Sale: $");
        fgets(amountStr, sizeof(amountStr), stdin);
        amountStr[strcspn(amountStr, "\n")] = 0;

        double amount = atof(amountStr);

        Invoice invoice;
        if (process(accounts, MAX_ACCOUNTS, input, amount, &invoice)) {
            printInvoice(invoice);
        }
    }

    return 0;
}
