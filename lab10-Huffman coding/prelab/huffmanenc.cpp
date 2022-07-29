#include <iostream>
#include "heap.h"
#include "huffmanNode.h"
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;


void allPaths(huffmanNode* node,  string code, unordered_map<char,string>& codes){
  if(node->right==NULL && node->left == NULL){
    codes.insert({node->value, code});
  }
  if(node->right != NULL)
    allPaths(node->right, code+"1", codes);
  if(node->left!= NULL)
    allPaths(node->left, code+"0", codes);
}

void printBT(const string& prefix, const huffmanNode* node, bool isLeft){
  if(node != NULL){
    cout<< prefix;
    cout<<(isLeft ? "|--" : "|__");
    cout<< node->freq<<endl;
    printBT(prefix + (isLeft ? "|   " : "   "), node->left, true);
    printBT(prefix + (isLeft ? "|   " : "   "), node->right, false);
  }
}
void printBT(const huffmanNode* node){
  printBT("", node, false);
}

int main(int argc, char** argv) {

  unordered_map<char, int> frequency;
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of the file)
    char g;
    while (file.get(g)) {
	if(g >= 0x20 && g <= 0x7e){
	  if(frequency.find(g) == frequency.end())
	    frequency[g] = 0;
	  frequency.at(g)++;
	}
    }

    vector<huffmanNode*> forest;
    int i = 0;
    for(auto &x : frequency){
      //cout<<x.first<<" "<<x.second<<endl; //prints out frequencies
      huffmanNode* temp = new huffmanNode();
      temp->value = x.first;
      temp->freq = x.second;
      forest.push_back(temp);
      i++;
    }
    
    
    heap minHeap(forest);
    while(minHeap.size()!=1){       // creates huffman tree
      huffmanNode* parent = new huffmanNode();
      
      parent->freq = minHeap.findMin()->freq;
      parent->left = minHeap.findMin();
      minHeap.deleteMin();
      
      parent->freq += minHeap.findMin()->freq;
      parent->right = minHeap.findMin();
      minHeap.deleteMin();

      minHeap.insert(parent);

      
      
    }

    string code = "";
    unordered_map<char, string> codes;
    printBT(minHeap.findMin());
    allPaths(minHeap.findMin(),code, codes);


    for(auto &x : codes){
      if(x.first == ' ')
	cout<< "space " << x.second <<endl;
      else
	cout<<x.first<< " " <<x.second<<endl;
    }

   int codeSize = codes.size();
    
    // a nice pretty separator
    cout << "----------------------------------------" << endl;

    // once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);
    int cmpFile = 0;
    while (file.get(g)) {
	cout<< codes[g]<< " ";
	cmpFile+=codes[g].length();
	}
    cout<<endl;
    cout << "----------------------------------------" << endl;
    // close the file
    file.close();
    double ratio = (double)minHeap.findMin()->freq*8/(double)cmpFile;
    double cost = (double)cmpFile/(double)minHeap.findMin()->freq;
    cout<<"There are a total of " << minHeap.findMin()->freq<<" symbols that are encoded."<<endl<<"There are "<<codeSize<<" distinct symbols used."<<endl<<"There were "<< minHeap.findMin()->freq*8<<" bits in the original file." <<endl<<"There were " <<cmpFile<<" bits in the compressed file."<<endl<<"This gives a compression ratio of " << ratio<<"."<<endl<<"The cost of the Huffman tree is "<<cost<<" bits per character"<<endl;
    return 0;
}
