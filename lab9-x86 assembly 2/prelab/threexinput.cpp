#include <iostream>
#include "timer.cpp"
using namespace std;

extern "C" int threexplusone(int x);

int main(){
  int x;
  int n;
  cout<<"Enter a number: " ;
  cin>>x;
  cout<<"Enter iterations of subroutine: ";
  cin>>n;
  int steps;
  steps = threexplusone(x);
  cout<< "Steps: " << steps<<endl;

  timer t;
  t.start();
  for(int i = 0; i<n; i++)
    steps = threexplusone(x);
  t.stop();
  t.getTime();
  return 0;
}
