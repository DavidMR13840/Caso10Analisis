#ifndef MATROID_H
#define MATROID_H

#include <iostream>
#include <string>
#include <matroidprocessor.h>
#include <functional>

using namespace std;

template <class T, typename F>
class Matroid
{
private:

public:
    Matroid(T array[], int size, F matroidFunction );
    function<void()> callback;
    T* setS;
    T* subsetI;
    int size_;
};

template <class T, typename F>
Matroid<T,F>::Matroid(T array[], int size, F matroidFunction){
    subsetI = NULL;
    callback = matroidFunction;
    size_ = size;
    for(int counter = 0; counter < size; counter++){
        setS[counter] = array[counter];
    }

}

#endif // MATROID_H
