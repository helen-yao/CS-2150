#include <iostream>
#include "hashTable.h"
#include <string>
#include <cstdlib>
#include <math.h>

using namespace std;

hashTable::hashTable(int size){
  tableSize = size;
  table = new string[size];
}

hashTable::~hashTable(){
  delete[] table;
}

void hashTable::insert(string value){
  int count = map(value);

     while(table[count] !=""){
       if(table[count] == "")
	 break;
       else{
	 count++;
       }
     }
     table[count] = value;
    
}

int hashTable::map(string value){
  int sum = 0;
  for(int i = 0; i<value.length(); i++){
    sum += value[i]*751;
  }
  return sum%tableSize;
}


bool hashTable::find(string value){
  int count = map(value);
  if(value == table[count])
    return true;
  while(table[count] != ""&&count<tableSize){
   if(table[count] != value)
     count++;
   if(value == table[count])
      return true;
  }
  return false;
}
