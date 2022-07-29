#include <iostream>
#include "postfixCalculator.h"

using namespace std;

postfixCalculator::postfixCalculator(){
  Stack myStack;
}

void postfixCalculator::Add(){
  int x = myStack.top();
  myStack.pop();
  int y = myStack.top();
  myStack.pop();
  myStack.push(x+y);

  }

void postfixCalculator:: Subtract(){
  int x = myStack.top();
  myStack.pop();
  int y = myStack.top();
  myStack.pop();
  myStack.push(y-x);
  }

Stack postfixCalculator:: getStack(){
  return myStack;
}

void postfixCalculator:: addElement(int num){
  myStack.push(num);
}

void postfixCalculator:: result(){
  if(myStack.size() == 1)
    cout << myStack.top() << endl;
  else 
    cout << "no numbers to compute" << endl;
}

void postfixCalculator:: Multiply(){
  int x = myStack.top();
  myStack.pop();
  int y = myStack.top();
  myStack.pop();
  myStack.push(x*y);
}

void postfixCalculator:: Divide(){
  int x = myStack.top();
  myStack.pop();
  int y = myStack.top();
  myStack.pop();
  myStack.push(y/x);
}

void postfixCalculator:: Negation(){
  int x = myStack.top();
  myStack.pop();
  myStack.push(-x);
}
