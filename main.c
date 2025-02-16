
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char username[50];
    char password[50];
    float balance;
} Account;

void createAccount();
void login(Account *acc);
void deposit(Account *acc);
void withdraw(Account *acc);
void checkBalance(Account *acc);
void updateAccountInfo(Account *acc);
void transferMoney(Account *sender);

int main() {
    Account acc;
    int choice;

    do {
        printf("--BANK MANAGEMENT SYSTEM--\n1. Create Account\n2. Login\n3. Deposit\n4. Withdraw\n5. Check Balance\n6. Update Account Info\n7. Transfer Money\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
        
                createAccount();
                break;
            case 2:
                login(&acc);
                break;
            case 3:
                deposit(&acc);
                break;
            case 4:
                withdraw(&acc);
                break;
            case 5:
                checkBalance(&acc);
                break;
            case 6:
                updateAccountInfo(&acc);
                break;
            case 7:
                transferMoney(&acc);
                break;
            case 8:
                printf("Successfully Exited\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}

void createAccount() {
    Account acc;
    FILE *file = fopen("accounts.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", acc.username);
    printf("Enter password: ");
    scanf("%s", acc.password);
    acc.balance = 0.0;

    fprintf(file, "%s %s %.2f\n", acc.username, acc.password, acc.balance);
    fclose(file);

    printf("Account created successfully!\n");
}

void login(Account *acc) {
    Account temp;
    FILE *file = fopen("accounts.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", acc->username);
    printf("Enter password: ");
    scanf("%s", acc->password);

    while (fscanf(file, "%s %s %f", temp.username, temp.password, &temp.balance) != EOF) {
        if (strcmp(temp.username, acc->username) == 0 && strcmp(temp.password, acc->password) == 0) {
            acc->balance = temp.balance;
            fclose(file);
            printf("Login successful!\n");
            return;
        }
    }

    fclose(file);
    printf("Invalid credentials!\n");
}

void deposit(Account *acc) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    acc->balance += amount;

    FILE *file = fopen("accounts.txt", "r+");
    Account temp;
    int found = 0;
    fseek(file, 0, SEEK_SET);
    while (fscanf(file, "%s %s %f", temp.username, temp.password, &temp.balance) != EOF) {
        if (strcmp(temp.username, acc->username) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        fseek(file, -strlen(temp.username) - strlen(temp.password) - sizeof(float) - 3, SEEK_CUR);
        fprintf(file, "%s %s %.2f\n", acc->username, acc->password, acc->balance);
    }   
    fclose(file);

    printf("Deposit successful!\n");
}

void withdraw(Account *acc) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > acc->balance) {
        printf("Insufficient balance!\n");
        return;
    }

    acc->balance -= amount;

    FILE *file = fopen("accounts.txt", "r+");
    Account temp;
    int found = 0;
    fseek(file, 0, SEEK_SET);
    while (fscanf(file, "%s %s %f", temp.username, temp.password, &temp.balance) != EOF) {
        if (strcmp(temp.username, acc->username) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        fseek(file, -strlen(temp.username) - strlen(temp.password) - sizeof(float) - 3, SEEK_CUR);
        fprintf(file, "%s %s %.2f\n", acc->username, acc->password, acc->balance);
    }
    fclose(file);

    printf("Withdrawal successful!\n");
}

void checkBalance(Account *acc) {
    printf("Current balance: %.2f\n", acc->balance);
}

void updateAccountInfo(Account *acc) {
    printf("Enter new username: ");
    scanf("%s", acc->username);
    printf("Enter new password: ");
    scanf("%s", acc->password);

    FILE *file = fopen("accounts.txt", "r+");
    Account temp;
    int found = 0;
    fseek(file, 0, SEEK_SET);
    while (fscanf(file, "%s %s %f", temp.username, temp.password, &temp.balance) != EOF) {
        if (strcmp(temp.username, acc->username) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        fseek(file, -strlen(temp.username) - strlen(temp.password) - sizeof(float) - 3, SEEK_CUR);
        fprintf(file, "%s %s %.2f\n", acc->username, acc->password, acc->balance);
    }
    fclose(file);

    printf("Account information updated successfully!\n");
}

void transferMoney(Account *sender) {
    Account receiver;
    char receiverUsername[50];
    float amount;
    int found = 0;

    printf("Enter receiver's username: ");
    scanf("%s", receiverUsername);
    printf("Enter amount to transfer: ");
    scanf("%f", &amount);

    if (amount > sender->balance) {
        printf("Insufficient balance!\n");
        return;
    }

    FILE *file = fopen("accounts.txt", "r+");
    while (fscanf(file, "%s %s %f", receiver.username, receiver.password, &receiver.balance) != EOF) {
        if (strcmp(receiver.username, receiverUsername) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Receiver not found!\n");
        fclose(file);
        return;
    }

    sender->balance -= amount;
    receiver.balance += amount;

    fseek(file, -strlen(receiver.username) - strlen(receiver.password) - sizeof(float) - 3, SEEK_CUR);
    fprintf(file, "%s %s %.2f\n", receiver.username, receiver.password, receiver.balance);

    fseek(file, 0, SEEK_SET);
    while (fscanf(file, "%s %s %f", receiver.username, receiver.password, &receiver.balance) != EOF) {
        if (strcmp(receiver.username, sender->username) == 0) {
            fseek(file, -strlen(receiver.username) - strlen(receiver.password) - sizeof(float) - 3, SEEK_CUR);
            fprintf(file, "%s %s %.2f\n", sender->username, sender->password, sender->balance);
            break;
        }
    }

    fclose(file);

    printf("Transfer successful!\n");
}
