#include <iostream>
#include <string>
#include "postfixCalculator.h"


using namespace std;


  int main(){
  postfixCalculator myStack;
  string token;
  while (cin >> token) {
    
      if(token == "+"){
	myStack.Add();
      }
      else if(token == "*"){
	myStack.Multiply();
      }
      else if(token == "/"){
	myStack.Divide();
      }
      else if(token == "~"){
	myStack.Negation();
      }
      else if(token == "-"){
	myStack.Subtract();
      }
      else{
	int num = stoi(token);
	myStack.addElement(num);
      }
  }
  myStack.result();
  return 0;
 }

