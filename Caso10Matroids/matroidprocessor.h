#ifndef MATROIDPROCESSOR_H
#define MATROIDPROCESSOR_H
#include <iostream>

using namespace std;

template <class T>
class MatroidProcessor
{
private:
    T* Matroids;
    int size_;
public:

    MatroidProcessor(T array[], int size) {}
    void processA();
    void processB();
};

template <class T>
MatroidProcessor::MatroidProcessor(T array[], int size){
    Matroids = new T[size];
    size_ = size;
    for(int counter = 0; counter < size; counter++){
        Matroids[counter] = array[counter];
    }
}

template <class T>
MatroidProcessor::processA(){
#pragma omp parallel for
    for(int counter = 0; counter < size_;counter++){
        Matroids[counter]();
    }
}


#endif // MATROIDPROCESSOR_H
