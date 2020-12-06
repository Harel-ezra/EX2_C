#ifndef _myBank_H_
#define _myBank_H_

extern double bank [50][2]; // balance and state of account, 0 is close, 1 is open
extern int counter;

void start();
void open(double sum);// opan a new account
void balance(int number);//print the balance at the account
void deposit(int number, double sum); // deposit to account
void withrawal(int number, double sum); // withrawal from account
void close(int number); // close an account
void interst(double x); //add inseret
void print();// print all open account at the bank
void end();// close all account at the bank and end the program
int validAccountNumber(int n);
int openAccountNumber(int n);
#endif