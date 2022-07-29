#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <queue>
using namespace std;
/*********
 *
 * \date      4/25/2022
 * \author   Helen Yao
 *! \brief    This program will topological sort a DAG
 ********/





int main(int argc, char** argv){
  /*
  fstream file;
  file.open(argv[1]);
  */
  ifstream file(argv[1]);
  if(!file.is_open())
    cout<<"error"<<endl;

  string classN;
  vector <string> classes;
  int classSize = 0;
  bool isIn = false;
  while(file >> classN){//puts all classes into vector clas
    if(classN != "0"){
      isIn = false;
      for(int i = 0; i<classes.size(); i++){
	if(classes[i] == classN)
	  isIn = true;
      }
      if(isIn == false){
	classes.push_back(classN);
	classSize++;
      }
    }
  }
  int matrix [classes.size()][classes.size()];
  for(int i = 0; i<classes.size(); i++){
    for(int j = 0; j<classes.size(); j++){
      matrix[i][j] = 0;
    }
  }
  string x,y;
  int rCount = 0;
  int cCount = 0;
  file.clear();
  file.seekg(0);
  while(file >> x >> y){
    for(int i = 0;i<classes.size(); i++){
      if(classes[i] == x)
	rCount = i;
      if(classes[i] == y)
	cCount = i;
    }
    matrix[rCount][cCount] = 1;
  }
  
  /*
  for(int i = 0; i<classes.size(); i++)
    cout<<classes[i]<<endl;
  
  for(int i = 0; i<classes.size(); i++){
    for(int j = 0; j<classes.size(); j++)
      cout<<matrix[i][j];
    cout<<endl;
  }
  */

  queue <string> q;
  int indegree = 0;
  string className;
  vector<int> adj;
  vector<string> output;
  for(int i = 0; i<classes.size(); i++){
    indegree = 0;
    for(int j = 0; j<classes.size(); j++){
      if(matrix[j][i] == 1)
	indegree++;
    }
    if(indegree == 0){
      q.push(classes[i]);
      for(int j = 0; j<classes.size(); j++){
	matrix[i][j] = 0;
    }
  }
  }



  while(!q.empty()){
      for(int i = 0 ; i<q.size(); i++){
	isIn = false;
	for(int j = 0; j<output.size(); j++){
	  if(q.front() == output[j])
	    isIn = true;
	}
	if(isIn == false)
	  output.push_back(q.front());
	q.pop();
      }
    for(int i = 0; i<classes.size(); i++){
      indegree = 0;
      for(int j = 0; j<classes.size(); j++){
	if(matrix[j][i] == 1)
	  indegree++;
      }


      if(indegree == 0 && isIn == false){
	q.push(classes[i]);
	for(int j = 0; j<classes.size(); j++)
	  matrix[i][j] = 0;	
      }
    }
  }

  for(int i = 0; i<output.size(); i++)
    cout<<output[i]<<" ";

  cout<<endl;
  return 0;
}


