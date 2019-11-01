#ifndef MATROIDPROCESSOR_H
#define MATROIDPROCESSOR_H
#include <iostream>
#include <omp.h>
#include "matroid.h"
#include <vector>
#include <algorithm>
#include <set>

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
    void printMatroids();
};

MatroidProcessor::MatroidProcessor(vector<Matroid*> array, int size){
   matroids = array;
    size_ = size;
}

void MatroidProcessor::processA(){
 int currentMatroid;
 omp_set_nested(1);
#pragma omp parallel for default(shared) private (currentMatroid)
 for(currentMatroid = 0; currentMatroid < size_; currentMatroid++){
     matroids[currentMatroid]->matroidFunction();
     printf("Thread %d, iteration %d\n",omp_get_thread_num(),currentMatroid);
 }


}

void MatroidProcessor::printMatroids(){
    for(int currentMatroid = 0; currentMatroid < size_; currentMatroid++){
        matroids[currentMatroid]->printSubsetI();
    }
}

//solo funciona cuando los elementos de los matroids son int, se realizo de esta forma por cuestion de tiempo
//ademas que considere que es suficiente para probar el punto b)
void MatroidProcessor::processB(){
    processA();
    std::set<int> intersection;
    for(int currentMatroid = 0; currentMatroid < size_; currentMatroid++){
        for(int currentMatroidElement = 0; currentMatroidElement < matroids[currentMatroid]->Result.size();currentMatroidElement++){
            int processedElement = *(static_cast<int*>(matroids[currentMatroid]->Result[currentMatroidElement]));
            for(int otherMatroids = 0; otherMatroids< size_;otherMatroids++){
                if(otherMatroids != currentMatroid){
                    if(matroids[otherMatroids]->findSubset(processedElement)){
                        intersection.insert(processedElement);
                    }
                }

            }

        }
    }
    cout << "Interseccion: " ;
    set<int> ::iterator setIterator;
    for(setIterator = intersection.begin(); setIterator != intersection.end();++setIterator){
        cout << *setIterator << ' ';
    }
    cout << endl;
}




#endif // MATROIDPROCESSOR_H
