#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sys/time.h>
using namespace std;




int main() {
   struct timeval tim;
   gettimeofday(&tim, NULL);
   double start_time=tim.tv_sec+(tim.tv_usec/1000000.0);

    // Empty vector holding all names from file
    vector<string> names;

    // Read names from file data.txt
    ifstream in("data.txt");
    // ifstream in("pagecounts.txt");
    if(!in.is_open())
        cout << "Unable to open files\n";

    // this is wrong, by the way: while(in.good()){
    string word;
    while(getline(in, word))
            names.push_back(word);

    sort(names.begin(), names.end());

    // Loop to print names
    for (size_t i = 0; i < names.size(); i++)
        cout << names[i] << '\n';

   gettimeofday(&tim, NULL);  
   double end_time=tim.tv_sec+(tim.tv_usec/1000000.0);
   double runtime = end_time - start_time;
   cout << "Program ran in " << runtime << " seconds!!!" << endl;
}