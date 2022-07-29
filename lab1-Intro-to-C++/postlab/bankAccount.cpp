#include <iostream>
#include "bankAccount.h"

using namespace std;

bankAccount::bankAccount(){
  balance = 0.0;
}

bankAccount::bankAccount(double amount){
  balance = amount;
}

bankAccount:: ~bankAccount() {}

double bankAccount::withdraw(double amount){
  if(amount <= balance){
    balance = balance - amount;
    return balance;
  }
  else{
    return balance;
  }
}

double bankAccount::deposit(double amount){
  balance = balance + amount;
  return balance;
}

double bankAccount::getBalance(){
  return balance;
}
