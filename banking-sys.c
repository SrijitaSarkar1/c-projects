#include <stdio.h>

struct account {
    int accountNumber;
    char name[100];
    char password[50];
    double balance;
};

struct Transaction {
    int TransactionID;
    int accountNumber;
    char type[20];
    double Balance;
    double BalanceAfter;
};

int main() {
    int choice;

    while(1) {
        printf("\n==== Banking System====\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Transfer\n");
        printf("6. Check Balance\n");
        printf("7. Transaction History\n");
        printf("8. Search Accounts\n");
        printf("9. Display Accounts\n");
        printf("10. Close Accounts\n");
        printf("11. Exit\n");

        printf("Enter choice: \n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                 createAccount();
                 break;

            case 2:
                 login();
                 break;
            
            case 3:
                 deposit();
                 break;

            case 4:
                 withdraw();
                 break;
                
            case 5:
                 transfer();
                 break;

            case 6:
                 checkBalance();
                 break;

            case 7:
                 transactionHistory();
                 break;

            case 8:
                 searchAccount();
                 break;

            case 9:
                 displayAccount();
                 break;

            case 10:
                 closeAccount();
                  break;

            case 11:
                 return 0;

            default:
                 printf("Invalid Choice.\n");
        }
    }
}

void createAccount(struct Account account) {
     printf("\n====Create Account====\n");

     printf("Enter Account Number:   ");
     scanf("%d", &account->accountNumber);

     printf("Enter your name: ");
     scanf(" %[^\n]", &account->name);

     printf("Create a password: ");
     scanf("%49s", &account->password);

     printf("Enter Initial deposit: ");
     scanf("%1f", &account->balance);

     printf("\nAccount created successfully!\n");
    printf("Account Number: %d\n", account->accountNumber);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2lf\n", account->balance);

}