#include <iostream>
#include <math.h>

using namespace std;

class prelab4{
public:
  void sizeOfTest(){
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of bool: " << sizeof(bool) << endl;
    cout << "Size of int*: " << sizeof(int*) << endl;
    cout << "Size of char*: " << sizeof(char*) << endl;
    cout << "Size of double*: " << sizeof(double*) << endl;
  }

  void overflow(){
    unsigned int x = 4294967295;
    cout << x << " + 1 = " << x+1 << endl;
  }

  void outputBinary(unsigned int x){
    
    for(int i = 31; i>= 0; i--){
      if(x/pow(2,i) >= 1){
	 cout << 1;
	 x = x- pow(2,i);
      }
      else 
	cout << 0;
      
      if(i%4 == 0)
       cout<< " ";
    }
    cout << endl;
  }


	      
};

  int main(){
    prelab4 obj;
    unsigned int x;
    
    cin >> x;
    obj.sizeOfTest();
    obj.overflow();
    obj.outputBinary(x);
    return 0;
  }
