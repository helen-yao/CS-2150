#include <iostream>
#include <fstream>
#include "hashTable.h"
#include "timer.h"
#include <list>

using namespace std;

bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);
bool checkPrime(unsigned int n);
int getNextPrime(unsigned int n);

char grid [500][500];

int main(int argc, char** argv){
  timer time;
  time.start();
  hashTable dictionary(getNextPrime(1500000));
  fstream file;
  string word, dictionaryFile;
  int rows, cols;

  
  readInGrid(argv[2], rows, cols);
  
 
  dictionaryFile = argv[1];
  
  file.open(dictionaryFile.c_str());


  while(file >> word){
    dictionary.insert(word);
  }
  file.close();
  
  int wordCount = 0;
  string words;
  
    for(int r = 0; r<rows; r++){
      for(int c = 0; c<cols; c++){
	for(int dir = 0; dir<8;dir++){
	  for(int len = 3; len<=22; len++){
	    if(dictionary.find(getWordInGrid(r,c,dir,len,rows,cols))&&getWordInGrid(r,c,dir,len,rows,cols).length()>2&&len==getWordInGrid(r,c,dir,len,rows,cols).length()){
		string Srow = to_string(r);
		string Scol = to_string(c);
		if(dir == 0){
	        words += "N (" + Srow + "," + Scol+ "):" + getWordInGrid(r,c,dir,len,rows,cols)+"\n";
		}
		else if(dir == 1){
		  words  += "NE (" + Srow + "," + Scol+ "):" + getWordInGrid(r,c,dir,len,rows,cols)+"\n";
		}	        
		else if(dir == 2){
		  words  += "E (" + Srow + "," + Scol+ "):" + getWordInGrid(r,c,dir,len,rows,cols)+"\n";
		}	        
		else if(dir== 3){
		  words  += "SE (" + Srow + "," + Scol+ "):" + getWordInGrid(r,c,dir,len,rows,cols)+"\n";
		}		
		else if(dir ==4){
		  words  += "S (" + Srow + "," + Scol+ "):" + getWordInGrid(r,c,dir,len,rows,cols)+"\n";
		}
		else if(dir==5){
		   words  += "SW (" + Srow + "," + Scol+ "):" + getWordInGrid(r,c,dir,len,rows,cols)+"\n";
		}
		else if(dir==6){
		   words  += "W (" + Srow + "," + Scol+ "):" + getWordInGrid(r,c,dir,len,rows,cols)+"\n";
		}
		else if(dir==7){
		  words += "NW (" + Srow + "," + Scol+ "):" + getWordInGrid(r,c,dir,len,rows,cols)+"\n";
		}
	      wordCount++;

	    }

	}

      }
    }
  }
    cout<<words;
    cout<<wordCount<<" words found"<<endl;
   
    time.stop();
    //cout<<time;
  return 0;
}


string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}


bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }
    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    ///cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
	//cout << endl;
    }
    return true;
}


bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases        
        return false;
    if ( p == 2 ) // 2 is prime                                                
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime               
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p         
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us                              
}



