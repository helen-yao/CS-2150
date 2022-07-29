#include <iostream>
using namespace std;
class xToN{
  public:
    double exponent(int base, int exp){
      if(exp>0){
        if(exp == 1){
          return base;
        }
        else{
        return base*exponent(base, exp-1);
        }
      }
      else if(exp<0){
        if(exp == 0){
          return 1;
        }
        else{
          return 1.0/base*exponent(base, exp+1);
        }
      }
      else{
        return 1;
      }
    }
