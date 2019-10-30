#ifndef MATROIDPROCESSOR_H
#define MATROIDPROCESSOR_H
#include <iostream>
#include <omp.h>
#include "matroid.h"
#include <vector>

using namespace std;

class MatroidProcessor
{
private:
    int size_;
    vector<Matroid*> matroids;
public:

    MatroidProcessor(vector<Matroid*> array, int size);
    void processA();
    void processB();
};

MatroidProcessor::MatroidProcessor(vector<Matroid*> array, int size){
   matroids = array;
    size_ = size;
}

void MatroidProcessor::processA(){
 int currentMatroid;
#pragma omp parallel for default(shared) private (currentMatroid)
 for(currentMatroid = 0; currentMatroid < size_; currentMatroid++){
     matroids[currentMatroid]->matroidFunction();
     printf("Thread %d, iteration %d\n",omp_get_thread_num(),currentMatroid);
 }

 for(int currentMatroid = 0; currentMatroid < size_; currentMatroid++){
     matroids[currentMatroid]->printSubsetI();
 }
}



#endif // MATROIDPROCESSOR_H
