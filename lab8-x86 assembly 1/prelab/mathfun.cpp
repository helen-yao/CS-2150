#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" int product(int,int);
extern "C" int power(int, int);

int main(){
  int x,y,pdtResult,pwrResult;

  
  cout << "Enter integer 1: ";
  cin>>x;
  cout<< "Enter integer 2: ";
  cin>>y;
  pdtResult = product(x,y);
  cout<<"Product: " << pdtResult<<endl;
  pwrResult = power(x,y);
  cout<<"Power: " << pwrResult<<endl;
  return 0;
}
