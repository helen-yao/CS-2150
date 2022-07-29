
#include "huffmanNode.h"
#include <iostream>
using namespace std;


huffmanNode::huffmanNode(){
  value =0;
  freq = 0;
  code = "";
  left = NULL;
  right = NULL;
}

huffmanNode::~huffmanNode(){
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}
