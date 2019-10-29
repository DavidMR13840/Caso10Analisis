#ifndef MATROID_H
#define MATROID_H

#include <iostream>
#include <string>
#include <matroidprocessor.h>
#include <functional>

using namespace std;

class Matroid
{
private:

public:
    template <typename F>
    Matroid(void* elements, int size,F functionToCall);
    function<void()> matroidFunction;
    void* setS;
    void* subsetI;
    int size_;
    void intFunction();
    void stringFunction();
    void booleanFunction();
};


template <typename F>
Matroid::Matroid(void* elements, int size,F functionToCall){
    subsetI = NULL;
    size_ = size;
    setS = elements;
    matroidFunction = std::bind(functionToCall,this);
}

void Matroid::intFunction(){
    int array[size_];
    int subsetIndex = 0;
    for(int elementIndex = 0; elementIndex < size_; elementIndex++){
        if(((int*)setS)[elementIndex] <= 10){
            array[subsetIndex] = ((int*)setS)[elementIndex];
            subsetIndex++;
        }
    }
    subsetI = array;
}



#endif // MATROID_H
