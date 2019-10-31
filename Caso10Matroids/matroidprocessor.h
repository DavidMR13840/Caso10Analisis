#ifndef MATROIDPROCESSOR_H
#define MATROIDPROCESSOR_H
#include <iostream>
#include <omp.h>
#include "matroid.h"
#include <vector>
#include <algorithm>

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
    bool compareMatroidsElement(int matroid, int matroidElement, vector<int> *intersection);
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
    this->processA();
    vector<int> intersection;
    for(int currentMatroid = 0; currentMatroid < size_; currentMatroid++){
        for(int matroidI = 0; matroidI < matroids[currentMatroid]->Result.size();matroidI++){
            if(compareMatroidsElement(currentMatroid,*(static_cast<int*>(matroids[currentMatroid]->Result[matroidI])),&intersection)){
                intersection.push_back(*(static_cast<int*>(matroids[currentMatroid]->Result[matroidI])));
            }
        }
    }
    cout << "Interseccion: " ;
    for(int vectorIndex = 0; vectorIndex < intersection.size();vectorIndex++){
        cout << intersection[vectorIndex] << " ";
    }
    cout << endl;
}

bool MatroidProcessor::compareMatroidsElement(int matroid, int matroidElement, vector<int> *intersection){
    bool isMember = false;
    for(int matroidIndex = 0; matroidIndex < size_; matroidIndex++){
        if(matroidIndex != matroid){
            if(std::find(intersection->begin(),intersection->end(),matroidElement) == intersection->end()){
                cout <<  matroids[matroid]->Result.size() << " ; " << matroid << endl;
                for(int subsetIndex = 0; subsetIndex < matroids[matroid]->Result.size();subsetIndex++){
                    if(*(static_cast<int*>(matroids[matroidIndex]->Result[subsetIndex])) == matroidElement){
                        isMember = true;
                        return isMember;
                    }
                }
            }
        }
    }
    return isMember;
}



#endif // MATROIDPROCESSOR_H
