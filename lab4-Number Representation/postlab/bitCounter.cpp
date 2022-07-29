#include <iostream>
#include <string>
#include <cmath>

using namespace std;

  int numberOfOnes(int x){
     if(x == 1){
      return 1;
    }
    else if(x == 0)
      return 0;

    else{
      
    if(x%2 == 0){
      return numberOfOnes(x/2);
      
    }
    if(x%2 == 1){
      return numberOfOnes(x/2)+1;
    }
    }

    
  }
  string baseConverter(int startBase, int endBase,string convert){
    int base10 = 0;
    int exp = 0;
    for(int i = convert.length()-1;i>=0;i--){
      if(isdigit(convert[i]))
	base10+=(convert[i]-48)*pow(startBase,exp);
      else
	base10+= (convert[i]-55)*pow(startBase,exp);
      exp++;
    }
    
    string converted = "";
    while(base10>0){
      if(base10 % endBase < 9)
	converted = to_string(base10 % endBase)+converted;
      else
	converted = char(base10 % endBase+55)+converted;

      base10 = base10/endBase;
    }
    return converted;
  }
  

  
int main(int argc, char** argv){
    cout << argv[1]<< " has " << numberOfOnes(atoi(argv[1])) << " bit(s)"<<endl;
    cout << argv[2] << " (base " << argv[3] << ") = " << baseConverter(atoi(argv[3]),atoi(argv[4]),argv[2])<< " (base " << argv[4]<< ")"<<endl;
     return 0;
}
