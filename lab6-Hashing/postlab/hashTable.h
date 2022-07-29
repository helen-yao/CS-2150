#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class hashTable{
 public:
  hashTable(int b);

  void insert(string value);

  bool find(string value);

  int map(string value);

  ~hashTable();
 private:
  string* table;
  int tableSize;



};
  #endif
