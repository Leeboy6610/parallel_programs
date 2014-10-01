// C++ Implementation

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <iostream>
#include <fstream>
#include <string>
#define numThreads 8

using namespace std;
std::ifstream ifs ("Human_MtDNA.txt");
std::string str ("GAAAAT");
std::string line;
int totalCount = 0;

// pthread_mutex_t lock;
// pthread_t threads[numThreads];

int countSubstring(const std::string& str, const std::string& sub)
{
    if (sub.length() == 0) return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;
    offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}

int matchCount()
{
   int lineno = 0;
   // pthread_mutex_lock(&lock);
   while(std::getline(ifs, line)){
   lineno++;
   totalCount = countSubstring(line, str) + totalCount;
      if(countSubstring(line, str)>0){
         std::cout << countSubstring(line, str) << " GAAAAT's were found in line " << lineno << endl;
      }
   }
   // pthread_mutex_unlock(&lock);
   return totalCount;
}

int main ()
{
   struct timeval tim;
   gettimeofday(&tim, NULL);
   double start_time=tim.tv_sec+(tim.tv_usec/1000000.0);
   matchCount();
   // pthread_mutex_init(&lock,NULL);
   // for(int i=0;i<numThreads;i++){
   //    pthread_create(&(threads[i]), NULL, matchCount, NULL);
   // }
   // for(int t=0;t<numThreads;t++){
   //    pthread_join(threads[t], NULL);
   // }
   // pthread_mutex_destroy(&lock);
   gettimeofday(&tim, NULL);  
   double end_time=tim.tv_sec+(tim.tv_usec/1000000.0);
   double runtime = end_time - start_time;
   cout << totalCount << " GAAAAT's were found in the file in " << runtime << " seconds!!!" << endl;
   return 0;
}