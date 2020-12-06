#include <stdio.h>
#include "myBank.h"

double bank[50][2];
int counter = 0;

void start()
{
    for (int i = 0; i < 50; i++)
    {
        bank[i][0] = 0.00;
        bank[i][1] = 0.0;
    }
    return;
}

void open(double sum) // opan a new account
{
    if (sum < 0)
    {
        printf("please insert a valid amount\n");
        return;
    }
    if (counter < 50)
    {
        for (int i = 0; i < 50; i++)
        {
            if (bank[i][1] == 0.0)
            {
                bank[i][0] = sum;
                bank[i][1] = 1.0;
                printf("your number account is: %d\n", 901 + i);
                counter++;
                return;
            }
        }
    }
    else
    {
        printf("The bank is full\n");
    }
    return;
}

void balance(int number) //print the balance at the account
{
    printf("The balance of account number %d is: %.2lf\n", number, bank[number - 901][0]);
    return;
}

void deposit(int number, double sum) // deposit to account
{
    if (sum > 0)
    {
        bank[number - 901][0] += sum;
        printf("The new balance is: %.2lf\n", bank[number - 901][0]);
    }
    else
    {
        printf("Cannot deposit a negative amount\n");
    }
    return;
}

void withrawal(int number, double sum) // withrawal from account
{

    if (sum < bank[number - 901][0] && sum > 0)
    {
        bank[number - 901][0] -= sum;
        printf("The new balance is: %.2lf\n", bank[number - 901][0]);
    }
    else
    {
        printf("Cannot withdraw more than the balance\n");
    }

    return;
}

void close(int number) // close an account
{
            bank[number - 901][0] = 0.00;
            bank[number - 901][1] = 0.0;
            printf("Closed account number is: %d\n", number);
            counter--;
    return;
}

void interst(double x) //add inseret
{
    for (int i = 0; i < 50; i++)
    {
        if (bank[i][1] == 1.0)
        {
            bank[i][0] *= ((100 + x) / 100);
        }
    }
    return;
}

void print() // print all open account at the bank
{
    for (int i = 0; i < 50; i++)
    {
        if (bank[i][1] == 1.0)
        {
            printf("The balance of account number %d is: %.2lf\n", i + 901, bank[i][0]);
        }
    }
    return;
}

void end() // close all account at the bank and end the program
{
    for (int i = 0; i < 50; i++)
    {
        bank[i][0] = 0.00;
        bank[i][1] = 0.0;
    }
    return;
}

int validAccountNumber(int number)
{
    if (number < 951 && number > 900)
    {
        return 1;
    }
    return 0;
}

int openAccountNumber(int n)
{
    if (bank[n - 901][1] == 1.0)
    {
        return 1;
    }
    return 0;
}