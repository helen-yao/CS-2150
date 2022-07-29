#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <string>

using namespace std;
class huffmanNode{
 public:
  huffmanNode();
  ~huffmanNode();

  char value;
  int freq;
  huffmanNode* right;
  huffmanNode* left;

};

#endif
