import java.util.*;
import java.math.BigDecimal;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Locale;

class Account {
    private final String accountNumber;
    private final String statusCode;

    public Account(String accountNumber, String statusCode) {
        if (accountNumber == null || accountNumber.trim().isEmpty()) {
            throw new IllegalArgumentException("accountNumber kosong");
        }
        if (statusCode == null) {
            throw new IllegalArgumentException("statusCode null");
        }
        this.accountNumber = accountNumber.trim();
        this.statusCode = statusCode.trim();
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public String getStatusCode() {
        return statusCode;
    }
}

class Invoice {
    private final String accountNumber;
    private final BigDecimal amountOfSale;

    public Invoice(String accountNumber, BigDecimal amountOfSale) {
        this.accountNumber = accountNumber;
        this.amountOfSale = amountOfSale;
    }

    public void printInvoice() {
        DecimalFormatSymbols syms = new DecimalFormatSymbols(Locale.US);
        DecimalFormat df = new DecimalFormat("#,##0.00", syms);
        System.out.println("\n=== INVOICE ===");
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Amount of Sale: $" + df.format(amountOfSale));
        System.out.println("===============\n");
    }
}

class AccountsRepo {
    private static final String STATUS_VALID = "valid";
    private final Map<String, Account> data = new HashMap<String, Account>();

    public AccountsRepo() {
        save(new Account("ACC001", "valid"));
        save(new Account("ACC002", "valid"));
        save(new Account("ACC003", "invalid"));
        save(new Account("ACC004", "valid"));
        save(new Account("ACC005", "suspended"));
    }

    public void save(Account acc) {
        data.put(acc.getAccountNumber(), acc);
    }

    public Account find(String accountNumber) {
        return data.get(accountNumber);
    }

    public static boolean isValidStatus(String status) {
        return STATUS_VALID.equalsIgnoreCase(status);
    }

    public Collection<Account> all() {
        return data.values();
    }
}

class BillingService {
    private final AccountsRepo repo;

    public BillingService(AccountsRepo repo) {
        this.repo = repo;
    }

    // Core logic sesuai pre/post conditions
    public Invoice process(String accountNumber, BigDecimal amountOfSale) {
        if (accountNumber == null || accountNumber.trim().isEmpty()) {
            throw new IllegalArgumentException("ERROR: account-number tidak boleh kosong.");
        }
        if (amountOfSale == null || amountOfSale.compareTo(BigDecimal.ZERO) < 0) {
            throw new IllegalArgumentException("ERROR: amount-of-sale harus >= 0.");
        }

        Account acc = repo.find(accountNumber.trim());
        if (acc == null) {
            // Postcondition 2
            throw new IllegalStateException("ERROR: Account number '" + accountNumber + "' not found in system.");
        }
        if (!AccountsRepo.isValidStatus(acc.getStatusCode())) {
            // Postcondition 2
            throw new IllegalStateException("ERROR: Account '" + accountNumber + "' status is '"
                    + acc.getStatusCode() + "'. Only 'valid' accounts can proceed.");
        }

        // Postcondition 1
        return new Invoice(acc.getAccountNumber(), amountOfSale);
    }
}

public class Main {
    public static void main(String[] args) {
        AccountsRepo repo = new AccountsRepo();
        BillingService service = new BillingService(repo);
        Scanner scanner = new Scanner(System.in);

        System.out.println("=== SISTEM TRANSAKSI PELANGGAN ===");
        System.out.println("\nDaftar Akun yang Tersedia:");
        for (Account acc : repo.all()) {
            System.out.println("- " + acc.getAccountNumber() + " (Status: " + acc.getStatusCode() + ")");
        }

        while (true) {
            System.out.println("\n--- Menu Transaksi ---");
            System.out.print("Masukkan Account Number (atau 'exit' untuk keluar): ");
            String accountNumber = scanner.nextLine().trim();
            if ("exit".equalsIgnoreCase(accountNumber)) {
                System.out.println("Terima kasih telah menggunakan sistem ini.");
                break;
            }

            System.out.print("Masukkan Amount of Sale: $");
            String amountInput = scanner.nextLine().trim();

            try {
                // Pakai BigDecimal biar presisi uang aman
                BigDecimal amount = new BigDecimal(amountInput);
                if (amount.compareTo(BigDecimal.ZERO) < 0) {
                    System.out.println("ERROR: Amount of sale tidak boleh negatif.");
                    continue;
                }

                Invoice invoice = service.process(accountNumber, amount);
                invoice.printInvoice();

            } catch (NumberFormatException e) {
                System.out.println("ERROR: Format amount tidak valid. Masukkan angka yang benar.");
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            } catch (IllegalStateException e) {
                System.out.println(e.getMessage());
            }
        }

        // Jangan close scanner kalau masih mau pakai System.in di tempat lain.
        // scanner.close();
    }
}
