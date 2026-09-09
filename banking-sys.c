#include <stdio.h>
#include <string.h>

struct Account {
    int accountNumber;
    char name[100];
    char password[50];
    double balance;
    int active;
    int loggedIn;
};


/* FUNCTION PROTOTYPES */

void createAccount(struct Account *account);
void login(struct Account *account);
void deposit(struct Account *account);
void withdraw(struct Account *account);
void checkBalance(struct Account *account);
void searchAccount(struct Account *account);
void displayAccount(struct Account *account);
void closeAccount(struct Account *account);
void clearInputBuffer(void);


/* MAIN FUNCTION */

int main() {

    int choice;

    struct Account account = {0};

    while (1) {

        printf("\n=============================\n");
        printf("       BANKING SYSTEM\n");
        printf("=============================\n");

        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Check Balance\n");
        printf("6. Search Account\n");
        printf("7. Display Account\n");
        printf("8. Close Account\n");
        printf("9. Exit\n");

        printf("\nEnter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }


        switch (choice) {

            case 1:
                createAccount(&account);
                break;

            case 2:
                login(&account);
                break;

            case 3:
                deposit(&account);
                break;

            case 4:
                withdraw(&account);
                break;

            case 5:
                checkBalance(&account);
                break;

            case 6:
                searchAccount(&account);
                break;

            case 7:
                displayAccount(&account);
                break;

            case 8:
                closeAccount(&account);
                break;

            case 9:
                printf("\nThank you for using the Banking System!\n");
                return 0;

            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}


/* CLEAR LEFTOVER INPUT (used after a failed scanf, e.g. non-numeric menu choice) */

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* discard */
    }
}


/* CREATE ACCOUNT */

void createAccount(struct Account *account) {

    printf("\n===== CREATE ACCOUNT =====\n");

    if (account->active == 1) {
        printf("An active account already exists. Close it before creating a new one.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &account->accountNumber);

    printf("Enter your name: ");
    scanf(" %99[^\n]", account->name);

    printf("Create a password: ");
    scanf("%49s", account->password);

    printf("Enter Initial Deposit: ");
    scanf("%lf", &account->balance);


    if (account->balance < 0) {

        printf("Initial deposit cannot be negative.\n");

        account->balance = 0;
    }


    account->active = 1;
    account->loggedIn = 0;


    printf("\nAccount created successfully!\n");

    printf("Account Number: %d\n", account->accountNumber);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2lf\n", account->balance);
}


/* LOGIN */

void login(struct Account *account) {

    int accountNumber;
    char password[50];


    printf("\n===== LOGIN =====\n");


    if (account->active != 1) {

        printf("No active account exists.\n");

        return;
    }


    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);


    printf("Enter Password: ");
    scanf("%49s", password);


    if (accountNumber == account->accountNumber &&
        strcmp(password, account->password) == 0) {

        account->loggedIn = 1;

        printf("\nLogin successful!\n");
        printf("Welcome, %s!\n", account->name);

    }
    else {

        account->loggedIn = 0;

        printf("\nInvalid account number or password.\n");
    }
}


/* DEPOSIT */

void deposit(struct Account *account) {

    double amount;


    printf("\n===== DEPOSIT =====\n");


    if (account->active != 1) {

        printf("Account is closed or does not exist.\n");

        return;
    }

    if (account->loggedIn != 1) {

        printf("Please login first.\n");

        return;
    }


    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);


    if (amount <= 0) {

        printf("Invalid amount.\n");

        return;
    }


    account->balance += amount;


    printf("\nDeposit successful!\n");

    printf("Deposited: %.2lf\n", amount);
    printf("New Balance: %.2lf\n", account->balance);
}


/* WITHDRAW */

void withdraw(struct Account *account) {

    double amount;


    printf("\n===== WITHDRAW =====\n");


    if (account->active != 1) {

        printf("Account is closed or does not exist.\n");

        return;
    }

    if (account->loggedIn != 1) {

        printf("Please login first.\n");

        return;
    }


    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);


    if (amount <= 0) {

        printf("Invalid amount.\n");

        return;
    }


    if (amount > account->balance) {

        printf("Insufficient balance.\n");

        return;
    }


    account->balance -= amount;


    printf("\nWithdrawal successful!\n");

    printf("Withdrawn: %.2lf\n", amount);
    printf("Remaining Balance: %.2lf\n", account->balance);
}


/* CHECK BALANCE */

void checkBalance(struct Account *account) {

    printf("\n===== CHECK BALANCE =====\n");


    if (account->active != 1) {

        printf("Account is closed or does not exist.\n");

        return;
    }

    if (account->loggedIn != 1) {

        printf("Please login first.\n");

        return;
    }


    printf("Account Number: %d\n", account->accountNumber);
    printf("Account Holder: %s\n", account->name);
    printf("Current Balance: %.2lf\n", account->balance);
}


/* SEARCH ACCOUNT */

void searchAccount(struct Account *account) {

    int accountNumber;


    printf("\n===== SEARCH ACCOUNT =====\n");


    if (account->active != 1) {

        printf("No active account exists.\n");

        return;
    }


    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);


    if (accountNumber == account->accountNumber) {

        printf("\nAccount found!\n");

        printf("Account Number: %d\n", account->accountNumber);
        printf("Name: %s\n", account->name);
        printf("Balance: %.2lf\n", account->balance);

    }
    else {

        printf("\nAccount not found.\n");
    }
}


/* DISPLAY ACCOUNT */

void displayAccount(struct Account *account) {

    printf("\n===== ACCOUNT DETAILS =====\n");


    if (account->active != 1) {

        printf("No active account exists.\n");

        return;
    }

    if (account->loggedIn != 1) {

        printf("Please login first.\n");

        return;
    }


    printf("Account Number: %d\n", account->accountNumber);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2lf\n", account->balance);
}


/* CLOSE ACCOUNT */

void closeAccount(struct Account *account) {

    int confirmation;


    printf("\n===== CLOSE ACCOUNT =====\n");


    if (account->active != 1) {

        printf("Account is already closed or does not exist.\n");

        return;
    }

    if (account->loggedIn != 1) {

        printf("Please login first.\n");

        return;
    }


    printf("Account Number: %d\n", account->accountNumber);


    printf("\nAre you sure you want to close this account?\n");
    printf("Enter 1 for Yes, 0 for No: ");

    scanf("%d", &confirmation);


    if (confirmation == 1) {

        account->active = 0;
        account->loggedIn = 0;

        printf("\nAccount closed successfully.\n");

    }
    else {

        printf("\nAccount closure cancelled.\n");
    }
}