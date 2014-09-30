// C++ Implementation

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
std::ifstream ifs ("Human_MtDNA.txt");
std::string str ("GAAAAT");
std::string line;

void finder ()
{
   int count = 0;
   int lineno = 0;
   while(std::getline(ifs, line)){
      lineno++;
      // cout << line << endl;
      std::size_t found = line.find(str);
      if (found!=std::string::npos){
         count++;
         cout << "Found in line " << lineno << endl;
      }
      else{
         // cout << "Not Found in line " << lineno << endl;
      }
   }
   int runtime = 0;
   cout << count << " Inputs found in " << runtime << " seconds!!!" << endl;
}

int main ()
{
   finder ();
   return 0;
}