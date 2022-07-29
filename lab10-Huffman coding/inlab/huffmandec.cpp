// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "heap.h"
#include "huffmanNode.h"
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

void makeTree(char value, string code, huffmanNode* cur){
  if(code.length() == 1){
    huffmanNode* newNode = new huffmanNode();
    newNode->value = value;
    newNode->freq = 1;
    
    if(code.at(0) == '1')
      cur->right = newNode;
    else
      cur->left = newNode;
    return;
  }
  if(code.at(0) == '0'){
    if(cur->left == NULL){
      huffmanNode* Ltemp = new huffmanNode();
      cur->left = Ltemp;
    }
    code = code.substr(1, code.length());
    makeTree(value, code, cur->left);
  }

  else if(code.at(0) == '1'){
    if(cur->right == NULL){
      huffmanNode* Rtemp = new huffmanNode();
      cur->right = Rtemp;
    }
    code = code.substr(1, code.length());
    makeTree(value, code, cur->right);
  }
}



// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    
    // read in the first section of the file: the prefix codes
    vector<huffmanNode*> forest;
    huffmanNode* root = new huffmanNode();
    
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
     

	
        // do something with the prefix code
   

	makeTree(character.at(0), prefix, root);
    }

    
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }
    string allbits = sstm.str();

    // at this point, all the bits are in the 'allbits' string

    // close the file before exiting
    file.close();

    

    string decode = "";
    huffmanNode* newNode = root;
    for(int i = 0; i<allbits.size(); i++){
      if(allbits.at(i) == '0'){
	newNode = newNode->left;
	if(newNode->left == NULL){
	  decode+=newNode->value;
	  newNode = root;
	}
      }
      else if(allbits.at(i) == '1'){
	newNode = newNode->right;
	if(newNode->left == NULL){
	  decode+=newNode->value;
	  newNode = root;
	}
      }

    }
    cout<<decode<<endl;

    
    return 0;
}
