#include <stdio.h>

int main() {

    int pin;
    int correctPin = 1234;
    int attempts = 0;

    float balance = 10000.0;
    float amount;
    int choice;

    // PIN verification
    while (attempts < 3) {

        printf("Enter PIN: ");
        scanf("%d", &pin);

        if (pin == correctPin) {
            printf("Login successful!\n");
            break;
        }
        else {
            printf("Incorrect PIN.\n");
            attempts++;
        }
    }

    // Block after 3 failed attempts
    if (attempts == 3) {
        printf("Too many incorrect attempts. Card blocked.\n");
        return 0;
    }

    // ATM menu
    while (1) {

        printf("\n===== ATM MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Your balance is: Rs. %.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);

                if (amount > 0) {
                    balance = balance + amount;
                    printf("Deposit successful!\n");
                    printf("New balance: Rs. %.2f\n", balance);
                }
                else {
                    printf("Invalid amount.\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);

                if (amount <= 0) {
                    printf("Invalid amount.\n");
                }
                else if (amount > balance) {
                    printf("Insufficient balance.\n");
                }
                else {
                    balance = balance - amount;
                    printf("Withdrawal successful!\n");
                    printf("Remaining balance: Rs. %.2f\n", balance);
                }
                break;

            case 4:
                printf("Thank you for using the ATM!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}