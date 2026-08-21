#include <stdio.h>
#include <string.h>

struct Transaction {
    char type[15];
    double amount;
};

int main(void) {
    double balance = 1000.0, amt;
    int choice, count = 0;
    struct Transaction history[5];

    do {
        printf("\nATM Menu\n");
        printf("1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n4. View Last 5 Transactions\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Current balance: %.2f\n", balance);
                break;

            case 2:
                printf("Enter deposit amount: ");
                scanf("%lf", &amt);
                balance += amt;
                strcpy(history[count % 5].type, "Deposit");
                history[count % 5].amount = amt;
                count++;
                printf("Deposit successful. New balance: %.2f\n", balance);
                break;

            case 3:
                printf("Enter withdrawal amount: ");
                scanf("%lf", &amt);
                if (amt > balance) {
                    printf("Insufficient balance. Withdrawal not allowed.\n");
                } else {
                    balance -= amt;
                    strcpy(history[count % 5].type, "Withdraw");
                    history[count % 5].amount = amt;
                    count++;
                    printf("Withdrawal successful. New balance: %.2f\n", balance);
                }
                break;

            case 4:
                printf("Last five transactions:\n");
                if (count == 0) {
                    printf("No transactions yet.\n");
                } else {
                    int limit = count < 5 ? count : 5;
                    int start = count > 5 ? count - 5 : 0;
                    for (int i = 0; i < limit; i++) {
                        int idx = (start + i) % 5;
                        printf("%s %.2f\n", history[idx].type, history[idx].amount);
                    }
                }
                break;

            case 5:
                printf("Exiting ATM system.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
