#include <iostream>
#include <climits>
#include <limits>
#include <float.h>

using namespace std;

int main(){
  int x = 9;
  int int0  = 0;
  unsigned int uint0 = 0;
  float float0 = 0;
  double double0 = 0;
  char char0 = 0;
  bool bool0 = 0;
  int* intstar = NULL;
  char* charstar = NULL;
  double* doublestar = NULL;

  int intmax = INT_MAX;
  unsigned int uintmax = UINT_MAX;
  float floatmax = FLT_MAX;
  double doublemax = DBL_MAX;
  char charmax = CHAR_MAX;
  //bool boolmax = BOOL_MAX;
  /*
  int* intstarmax = INT*_MAX;
  char* charstarmax = CHAR*_MAX;
  double* doublestarmax = DBL*_MAX;
  */
  cout << "zeros: " << &int0<<endl<< uint0<<endl<< float0<<endl << double0<< endl << char0<< endl<< bool0<<endl<< intstar<< endl << charstar<< endl << doublestar<<endl;
  cout << "max: "<<endl << intmax<< endl << uintmax<<endl << floatmax<<endl << doublemax<<endl << charmax<<endl;
  //boolmax<<endl << instarmax<<endl <<charstarmax <<endl << doublestarmax<<endl;
};
  
