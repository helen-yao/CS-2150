#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack(){
}

int Stack::top(){
  ListItr temp (myStack.last());

  return temp.retrieve();
}

void Stack::pop(){
  ListItr temp(myStack.last());
  myStack.remove(temp.retrieve());
}

void Stack::push(int x){
  myStack.insertAtTail(x);
}

bool Stack::empty(){
  if(myStack.size() == 0)
    return true;
  return false;
}

int Stack::size(){
  return myStack.size();
}
