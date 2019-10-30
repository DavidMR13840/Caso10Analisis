#ifndef MATROID_H
#define MATROID_H

#include <iostream>
#include <string>
#include <matroidprocessor.h>
#include <functional>
#include <vector>

using namespace std;

class Matroid
{
private:

public:
    template <typename F>
    Matroid(void* elements, int size,F functionToCall, F printFunction);
    function<void()> matroidFunction;
    function<void()> printSubsetI;
    void* setS;
    void* subsetI;
    int size_;
    int subsetSize;
    vector<void*> Result;
    void intFunction();
    void stringFunction();
    void booleanFunction();
    void printInt();
    void printBoolean();
    void printString();
};


template <typename F>
Matroid::Matroid(void* elements, int size,F functionToCall, F printFunction){
    subsetI = NULL;
    size_ = size;
    setS = elements;
    matroidFunction = std::bind(functionToCall,this);
    printSubsetI = std::bind(printFunction,this);
}

void Matroid::intFunction(){
    for(int elementIndex = 0; elementIndex < size_; elementIndex++){
        if(*(static_cast<int*>(setS)+elementIndex) <= 10){
            Result.push_back((static_cast<int*>(setS)+elementIndex));
        }
    }

}

void Matroid::booleanFunction(){
    for(int elementIndex = 0; elementIndex < size_; elementIndex++){
        if(*(static_cast<bool*>(setS)+elementIndex) == true){
            Result.push_back((static_cast<bool*>(setS)+elementIndex));
        }
    }
}

void Matroid::stringFunction(){
    for(int elementIndex = 0; elementIndex < size_; elementIndex++){
        if((*(static_cast<string*>(setS)+elementIndex)).length() <= 6 ){
            Result.push_back((static_cast<string*>(setS)+elementIndex));
        }
    }
}

void Matroid::printString(){
    for(int items = 0; items < Result.size(); items++){
        cout << *(static_cast<string*>(Result[items])) << " ";
    }
    cout << endl;
}

void Matroid::printBoolean(){
    for(int items = 0; items < Result.size(); items++){
        cout << *(static_cast<bool*>(Result[items])) << " ";
    }
    cout << endl;
}

void Matroid::printInt(){
    for(int items = 0; items < Result.size(); items++){
        cout << *(static_cast<int*>(Result[items])) << " ";
    }
    cout << endl;
}




#endif // MATROID_H
