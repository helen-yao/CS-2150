#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "List.h"

using namespace std;

class Stack{
 public:
  Stack();

  int top();

  void pop();

  void push(int x);

  bool empty();

  int size();

private:
  List myStack;

};
#endif
