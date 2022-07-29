#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "Stack.h"

using namespace std;

class postfixCalculator{
 public:
  void Add();

  void Subtract();

  void Multiply();

  void Divide();

  void Negation();

  void result();

  Stack  getStack();

  void addElement(int num);

  postfixCalculator();
  
private:
  Stack myStack;
};

#endif
