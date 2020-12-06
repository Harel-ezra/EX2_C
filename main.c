#include <stdio.h>
#include "myBank.h"

int main()
{
    start();
    char ch;
    int numberAccount;
    double moneySum;
    double i;

    do
    {
        printf("\n");
        printf("Please choose a transaction type:\n");
        printf("O-Open Account\n");
        printf("B-Balance Inquiry\n");
        printf("D-Deposit\n");
        printf("W-Withdrawal\n");
        printf("C-Close Account\n");
        printf("I-Interest\n");
        printf("P-Print\n");
        printf("E-Exit\n");
        scanf(" %c", &ch);

        switch (ch)
        {
        case 'O':
            printf("Please enter amount for deposit: ");
            if (scanf("%lf", &moneySum) == 1)
            {
                open(moneySum);
            }
            else
            {
                printf("Failed to read the amount\n");
            }
            break;

        case 'B':
            printf("Please enter account number: ");
            if (scanf("%d", &numberAccount) == 1)
            {
                if (validAccountNumber(numberAccount) == 1)
                {
                    if (openAccountNumber(numberAccount) == 1)
                    {
                        balance(numberAccount);
                    }
                    else
                    {
                        printf("This account is closed\n");
                    }
                }
                else
                {
                    printf("Invalid account number\n");
                }
            }
            else
            {
                printf("Failed to read the account number\n");
            }
            break;

        case 'D':
            printf("Please enter account number: ");
            if (scanf("%d", &numberAccount) == 1)
            {
                if (validAccountNumber(numberAccount) == 1)
                {
                    if (openAccountNumber(numberAccount) == 1)
                    {
                        printf("Please enter amount for deposit: ");
                        if (scanf("%lf", &moneySum) == 1)
                        {
                            deposit(numberAccount, moneySum);
                        }
                        else
                        {
                            printf("Failed to read the amount\n");
                        }
                    }
                    else
                    {
                        printf("This account is closed\n");
                    }
                }
                else
                {
                    printf("Invalid account number\n");
                }
            }
            else
            {
                printf("Failed to read the account number\n");
            }
            break;

        case 'W':
            printf("Please enter account number: ");
            if (scanf("%d", &numberAccount) == 1)
            {
                if (validAccountNumber(numberAccount) == 1)
                {
                    if (openAccountNumber(numberAccount) == 1)
                    {
                        printf("Please enter amount for withrawal: ");
                        if (scanf("%lf", &moneySum) == 1)
                        {
                            withrawal(numberAccount, moneySum);
                        }
                        else
                        {
                            printf("Failed to read the amount\n");
                        }
                    }
                    else
                    {
                        printf("This account is closed\n");
                    }
                }
                else
                {
                    printf("Invalid account number\n");
                }
            }
            else
            {
                printf("Failed to read the account number\n");
            }

            break;

        case 'C':
            printf("Please enter account number: ");
            if (scanf("%d", &numberAccount) == 1)
            {
                if (validAccountNumber(numberAccount) == 1)
                {
                    if (openAccountNumber(numberAccount) == 1)
                    {
                        close(numberAccount);
                    }
                    else
                    {
                        printf("This account is closed\n");
                    }
                }
                else
                {
                    printf("Invalid account number\n");
                }
            }
            else
            {
                printf("Failed to read the account number\n");
            }

            break;

        case 'I':
            printf("Please enter interst rate:\n");
            if (scanf("%lf", &i) == 1)
            {
                interst(i);
            }
            else
            {
                printf("Failed to read interest rate\n");
            }
            break;

        case 'P':
            print();
            break;

        case 'E':
            end();
            break;

        default:
            printf("Invalid transaction type\n");
            break;
        }
    } while (ch != 'E');
    return 0;
}